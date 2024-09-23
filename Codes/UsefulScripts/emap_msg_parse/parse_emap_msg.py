import re

pattern = r'>>([a-z|A-Z]{4} msg)\[.*\]: (.*) :: (.*)'
SEND_MSG_PREFIX = 'Send msg '
RECV_MSG_PREFIX = 'Recv msg '
recvMsgDict = {}
sendMsgDict = {}

def read_file_by_line(file_path):
    cnt = 0
    with open(file_path, 'r', encoding='utf-8') as file:
        for line in file:
            log_line = line.strip()  # strip()去掉每行末尾的换行符
            msgTmp = re.findall(pattern, log_line)
            if len(msgTmp) != 0:
                if msgTmp[0] is not None:
                    if SEND_MSG_PREFIX in msgTmp[0][0]:
                        sendMsgDict[msgTmp[0][0] + f' {cnt}'] = [msgTmp[0][1], msgTmp[0][2]]
                        cnt += 1
                    else:
                        recvMsgDict[msgTmp[0][0] + f' {cnt}'] = [msgTmp[0][1], msgTmp[0][2]]
                        cnt += 1
    return recvMsgDict, sendMsgDict

def parse_header(header: str):
    pat = '([\d|A-F]{2})'
    msgListTmp = re.findall(pat, header)
    msgList = [ msgListTmp[0], msgListTmp[1] ]
    msgList.reverse()
    print(msgList)

if __name__ == '__main__':
    t = ('Recv msg', '21:43:30.154')
    print(t[1])
    # rDict, sDict = read_file_by_line('emap_msg_log.txt')
    # parse_header(rDict[RECV_MSG_PREFIX + '8430'][0])
