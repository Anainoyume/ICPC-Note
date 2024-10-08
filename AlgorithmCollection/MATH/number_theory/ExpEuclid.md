## ��չŷ�Ｘ���㷨
�ڽ�����չŷ�Ｘ���㷨֮ǰ���Ƚ�����շת�������Ҳ����������Ϥ�� $\mathrm{gcd(a, b)}$��
���Ĵ��뾫���Ժ�ܼ򵥣�

```cpp
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
```


�����������о���չŷ�Ｘ���㷨��
����һ�㣺**��չŷ�Ｘ���㷨����������ģ�**

��չŷ�Ｘ���㷨�����������ҳ� $\mathrm{gcd(a,b)}$ ��ͬʱ�������
$$
ax+by=gcd(a,b)
$$
��һ���⡣

����֪��һ�㣬����շת�������ԭ�������У�
$$
gcd(a,b) = gcd(b,a~\mathrm{mod}~b)
$$

��ô�����Ƿ�Ҳ�У�
$$
bx'+ (a~\mathrm{mod}~b)y' = gcd(a,b)
$$
�����ԣ��ǵģ����ǿ��Ա�֤�ұߵ�ʽ�Ӳ��������¡�һ·����������ȥ������֪�����һ����ó�һ��������ʽ�ӡ���ʱֻ��ʣ�� $x'$ һ��δ֪�����������ڱ�������ֵ���� $gcd(a,b)$�����Ի���� $x'=1$��

��ô���ڲ��ݽ���շת�����ʽ�ӣ�$x$ �� $x'$ �Ĺ�ϵ��ʲô�����أ�
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

������������дһ����δ��룺
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

���ǿ����ٱ仯һ����δ��룬ʹ����ø��Ӽ�ࣺ
�������´��ݵ�ʱ�򽻻��� $x$ �� $y$����ô���ݻ�����ʱ��$x$ �� $y$ ��ȻҲ���෴�ġ����൱�� $x$���Ѿ�����һ�ν����ˡ���ʱ $x0 = y, y0 = x$����ô `y = x0 - (a / b) * y0` �ͱ���� `y = y - (a / b) * x`��
Ҳ���� `y -= (a / b) * x`
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
