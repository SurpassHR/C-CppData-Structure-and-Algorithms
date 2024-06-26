# C++语言实战进阶

## 运算符优先级

| 优先级 | 运算符                   | 描述                                               | 结合性   |
|--------|--------------------------|----------------------------------------------------|----------|
| 1      | `::`                     | 作用域解析运算符                                   | 左结合   |
| 2      | `++` `--`                | 后置自增和自减                                     | 左结合   |
|        | `type()` `type{} `       | 类型转换                                           |          |
|        | `() ` `[]`               | 函数调用，数组下标                                 |          |
| 3      | `++` `--`                | 前置自增和自减                                     | 右结合   |
|        | `+` `-`                  | 一元加，一元减                                     |          |
|        | `!` `~`                  | 逻辑非，按位非                                     |          |
|        | `&` `*`                  | 取地址，指针解引用                                 |          |
|        | `sizeof` `alignof`       | 对象大小，对齐大小                                 |          |
|        | `typeid`                 | 类型信息                                           |          |
|        | `static_cast` `dynamic_cast` | 类型转换                                      |          |
|        | `const_cast` `reinterpret_cast` | 类型转换                                    |          |
|        | `new` `delete`           | 动态内存分配                                       |          |
| 4      | `.*` `->*`               | 成员指针运算符                                     | 左结合   |
| 5      | `*` `/` `%`              | 乘，除，取模                                       | 左结合   |
| 6      | `+` `-`                  | 加，减                                             | 左结合   |
| 7      | `<<` `>>`                | 左移，右移                                         | 左结合   |
| 8      | `<` `<=` `>` `>=`        | 小于，小于等于，大于，大于等于                     | 左结合   |
| 9      | `==` `!=`                | 等于，不等于                                       | 左结合   |
| 10     | `&`                      | 按位与                                             | 左结合   |
| 11     | `^`                      | 按位异或                                           | 左结合   |
| 12     | `|`                      | 按位或                                             | 左结合   |
| 13     | `&&`                     | 逻辑与                                             | 左结合   |
| 14     | `||`                     | 逻辑或                                             | 左结合   |
| 15     | `? :`                    | 条件运算符                                         | 右结合   |
| 16     | `= += -= *= /= %= &= ^= |= <<= >>= ` | 赋值，复合赋值运算符                  | 右结合   |
| 17     | `,`                      | 逗号                                               | 左结合   |/

**例题:** 

2、当 $a = 6$ ， $b=5$ 时，这个表达式的值是多少: $b | a * b \& a + b$

解: 实际计算过程为
$$
\begin{align}
&(b | ((a * b) \& (a + b))) \\ =
&(5 | ((6 * 5) \& (6 + 5))) \\ =
&(101 | (111110 \& 1011))
\end{align}
$$
位与计算
$$
\begin{array}{r}
   & 111110 \\
\& & 001011 \\
\hline
   & 001010 \\
\end{array}
$$
位或计算
$$
\begin{array}{r}
   & 001010 \\
\& & 000101 \\
\hline
   & 001111 \\
\end{array}
$$
最终结果 $1111_{2} = 15_{10}$
