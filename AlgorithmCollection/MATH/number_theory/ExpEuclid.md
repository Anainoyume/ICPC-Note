## 扩展欧里几得算法
在介绍扩展欧里几得算法之前，先介绍求辗转相除法，也就是我们熟悉的 $\mathrm{gcd(a, b)}$。
他的代码精炼以后很简单：

```cpp
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
```


我们现在来研究扩展欧里几得算法。
首先一点：**扩展欧里几得算法是用来干嘛的？**

扩展欧里几得算法的作用是在找出 $\mathrm{gcd(a,b)}$ 的同时，求出：
$$
ax+by=gcd(a,b)
$$
的一个解。

我们知道一点，根据辗转相除法的原理，我们有：
$$
gcd(a,b) = gcd(b,a~\mathrm{mod}~b)
$$

那么我们是否也有：
$$
bx'+ (a~\mathrm{mod}~b)y' = gcd(a,b)
$$
很明显，是的，我们可以保证右边的式子不变的情况下。一路这样迭代下去，我们知道最后一定会得出一个整除的式子。届时只会剩下 $x'$ 一个未知量，并且由于被除数的值就是 $gcd(a,b)$，所以会求出 $x'=1$。

那么对于层层递进的辗转相除法式子，$x$ 与 $x'$ 的关系是什么样的呢？
$$
\begin{matrix}
    \because ~ bx'+ (a~\mathrm{mod}~b)y' = gcd(a,b)\\
    \\
    And \because ~ a~\mathrm{mod}~b = a - \lfloor{\frac{a}{b}}\rfloor\times b\\
    \\
    \therefore ~ bx'+ (a~\mathrm{mod}~b)y' = bx'+ (a - \lfloor{\frac{a}{b}}\rfloor\times b)y'\\
    \\
    And\because ~ bx'+ (a - \lfloor{\frac{a}{b}}\rfloor\times b)y' = ay'+ b(x'-\lfloor{\frac{a}{b}}\rfloor \times y') = gcd(a,b)\\
    \\
    \text{We have known that:} ~~ ax+by=gcd(a,b)\\
    \\
    \therefore ~ \left\{ \begin{aligned} x &= y'\\
    y &= x'-\lfloor{\frac{a}{b}}\rfloor\times y' \end{aligned} \right.
\end{matrix}
$$

现在我们再来写一下这段代码：
```cpp
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y), x0 = x, y0 = y;
    x = y0;
    y = x0 - (a / b) * y0;
    return d;
}
```

我们可以再变化一下这段代码，使它变得更加简洁：
我们向下传递的时候交换了 $x$ 和 $y$，那么回溯回来的时候，$x$ 和 $y$ 显然也是相反的。就相当于 $x$，已经做了一次交换了。此时 $x0 = y, y0 = x$，那么 `y = x0 - (a / b) * y0` 就变成了 `y = y - (a / b) * x`，
也就是 `y -= (a / b) * x`
```cpp
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
```
