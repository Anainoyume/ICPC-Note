> *The purpose of this note is to record some know-how and problem solving ideas about binary.*
-------------------------------------------------

**1. Binary ideas**
For a number, it can be split into the following form:
$$
N = a_n2^n+a_{n-1}2^{n-1}+\dots+a_22^2+a_12^1+a_02^0
$$
where $a_n,a_{n-1},\dots,a_0$ are $0$ or $1$.
Each term of this polynomial corresponds to each bit of binary.

For example:
$$
2^4+2^3+2^1+1 = (11011)_b = 27
$$

**2. Binary addition**
If we want to add $2^3$ and $2^2$, then we can understand the process in binary terms:
$$
(1000)_b + (0100)_b = (1100)_b
$$
So what if we are adding $2^3$ and $2^3$?
$$
(1000)_b + (1000)_b = (10000)_b
$$
**Applications:**
$\mathrm{How~to~proof:~~~If~~a < b < c,~~Then~~2^a + 2^b < 2^c}.$
This is obvious when we look at the binary:
$$
(...00001...)_b^a+(...00010...)_b^b < (...00100...)_b^c
$$
