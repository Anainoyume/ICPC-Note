1. 两个数字一个加1，一个减1，那么数列总和不变
<br>

2. **unordered_map** 可能被hack，解决方案是加上 `reserve(1024)` 和 `max_load_factor(0.25)`
<br>

3. **map**的**find**, **memset**, **fill** 都会影响一定效率, **数组查询是最快的**。但是要注意, 开的数组越大, 效率越低，举个例子: 如果有 `t` 个样例, 如果每次样例开的数组大小都是 `maxN`, 这样的效率会远远低于每次样例中动态分配内存的数组, 数组大小为 `n`, 就开`n+1` 或者 `n+2` 的数组, 这样会极大优化效率
<br>

4. `'\n'` 代替 `endl`, 会快很多, 尤其有大量输出的
<br>

5. 必要时可以加上流解绑, 即`ios::sync_with_stdio(false)`, `cout.tie(0)`, `cin.tie(0)`, 板子中直接使用 `IOS` 即可
<br>

6. $~~~~~~~~~~~k\mid a_i-a_j \\ \iff a_i-a_j = kn \\ \iff  a_i \equiv a_j\mod k \\ \iff a_i\mod k = a_j \mod k\\ \iff a_i,a_j余数相同$ 
<br>

7. $~~~~~~~~~~~(a_i+a_j)\mod k = 0 \\ \iff (a_i \mod k + a_j \mod k) \mod k = 0 \\ \iff a_i \mod k + a_j \mod k = k \\ \iff a_i \mod k + a_j \mod k = 0$
<br>

8. 字符大小写转换技巧：
```cpp
char c = 'a';

if (c & ' ') //判断是否为小写
if (~c & ' ') //判断是否为大写

c |= ' ' //转化为小写
c ^= ' ' //大小写互换
c = (c | ' ') ^ ' ' //转化为大写
```
<br>

9. 枚举类的设计
```cpp
enum BITFLAG : int
{
    invalid = 0,                 // 没有合法关系
    less = 1 << 0,               // 严格小于
    equal = 1 << 1,              // 严格等于
    greate = 1 << 2,             // 严格大于
    leq = less | equal,          // 小于等于
    geq = equal | greate,        // 大于等于
    neq = less | greate,         // 不等于
    full = less | equal | greate // 所有关系均可
};
```
<br>

10. **二进制**
$a~\&~b~\leq~\max(a,b)$ &nbsp; (很好证明)
如果对一个序列使用这个操作，例如：
$a_1\&a_2\&a_3\&\dots\&a_n\&\dots$
那么异或前缀会越来越小，满足单调性，只要有单调性就可以二分查找