## 查阅官方文档

### 流量统计配置方法

>## 流量统计 API (HTTP)
>
>流量统计 API 允许你通过 HTTP API 查询服务器的流量统计信息，以及踢用户下线。具体使用方法请参考 [流量统计 API 文档](https://v2.hysteria.network/zh/docs/advanced/Traffic-Stats-API/)。
>
>```yaml
>trafficStats:
>      listen: 127.0.0.1:9999 # 也可以监听公网端口0.0.0.0:9999，但是不安全，不建议使用
>      secret: some_secret 
>```
>
>> **注意：** 如果不设置密钥，任何能访问 API 监听地址的人都可以查询用户流量信息和踢用户下线。强烈建议设置密钥，或至少用 ACL 阻拦对 API 监听地址的访问。

### 流量统计接口使用方法

># 流量统计 API
>
>### GET `/traffic`
>
>此接口返回一个 JSON map，是每个用户的流量信息。
>
>响应：
>
>```json
>{
>      "wang": {
>        "tx": 514,
>        "rx": 4017
>      },
>      "joe": {
>        "tx": 7790,
>        "rx": 446623
>      }
>}
>```
>
>还可以使用参数 `clear` 在返回统计数据后将其清零：
>
>```
>/traffic?clear=1
>```

- 可知，通过本地访问 `hysteria` 监听的端口 `trafficStats.listen` 可以获取服务已经代理过的流量总量

  - 例，通过 `curl` 构建 `GET` 请求来获取 `/traffic` 的结果

    - 使用 `-H` 参数携带消息头 `'Key: Val'`，来通过密钥验证
    - `curl -H 'Authorization: <some_secret>' http://127.0.0.1:9999/traffic`

    ```bash
    # 返回结果
    {"user":{"tx":721976,"rx":6631619}}
    ```

## 请求转发

- 可以通过简单的网络服务应用，将通过域名访问的请求转发到 `hystaria` 监听的内部端口，实现公网流量查询

```python
import fastapi
import urllib.request
import urllib.parse
import json

app = fastapi.FastAPI()

HYS_TRAFFIC_STAT_LOCAL_LISTEN = 'http://127.0.0.1:9999'
HYS_TRAFFIC_STAT_HEADER = {
    'Authorization': 'ed9da2b7-676d-49d0-927a-eb78f319992b',
}

@app.get('/')
def redirect():
    return get_traffic_stats()

@app.get('/traffic')
def get_traffic_stats():
    data = get_data_from_hys('traffic')
    if data is None:
        return 'Failed get data'

    traffic_data = parse_traffic_data(data)
    if traffic_data is not None:
        return traffic_data
    else:
        return 'Failed parse data'

def parse_traffic_data(str_data):
    if len(str_data) == 0 or 'tx' not in str_data or 'rx' not in str_data:
        return None
    dict_data = json.loads(str_data)
    tx = dict_data['user']['tx']
    rx = dict_data['user']['rx']
    return f'tx: {int(tx)/1024/1024:.2f}GB, rx: {int(rx)/1024/1024:.2f}GB'

def get_data_from_hys(data: str):
    url = HYS_TRAFFIC_STAT_LOCAL_LISTEN + '/' + data
    req = urllib.request.Request(url)
    req.add_header('Authorization', 'ed9da2b7-676d-49d0-927a-eb78f319992b')
    resp = urllib.request.urlopen(req)
    content = resp.read().decode('utf-8')
    if 'user' in content:
        return content
    else:
        return None
```

- 需要注意的是 `fastapi` 仅支持 `http` 协议访问，所以还需要在 `cloudflare` 中配置一条规则，使强制通过 `https` 访问时的请求能够重定向到 `my.site.com` 的 `公网ip:fastapi监听端口`

- 后续可以学习下 `nginx` 反代，实现上述相同的功能
