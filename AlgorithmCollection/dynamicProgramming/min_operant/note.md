## Linear Dynamic Programming Topic:

### Edit Distance

***

Edit distance can also be referred to as the minimum operations problem. Such problems typically involve:
Given some operations, such as: **insert**, **replace**, **delete**
Some problems may have <u>variations`[n.变化,变种,差异]`</u> in the wording of the prompt or slight changes in operations:
For example: **regular expression matching**

Here, we will take **insert**, **replace**, **delete** as examples to provide a detailed explanation for this type of problem.

Here is an example:

### Edit Distance

Suppose $A$ and $B$ are two strings. We want to transform string $A$ into string $B$ with the minimum number of character operations. The character operations mentioned here include three types:

1. **Deleting** a character.
2. **Inserting** a character.
3. **Changing** one character to another.

$A$ and $B$ both only contain <u>lowercase letters`[n.小写字母]`</u>.

### Input Format

The first line contains string $A$, and the second line contains string $B$. The lengths of string $A$ and $B$ are both less than $2000$.

### Output Format

There is only one positive integer, representing the minimum number of character operations.

***

**How do we solve it?**
Let's review the three fundamental steps in solving dynamic programming problems:
**1. Design the DP array.
2. Design the state transition equation.
3. Code the details.**

So let's start with the first step.
This is a <u>dual-string`[n.双串]`</u> linear dynamic programming problem. Clearly, we need to design $dp[i][j]$.

So... what should its meaning be?

In such cases, we can design it based on the desired answer <u>as specified`[.按规定,指定]`</u> in the problem. For example, $dp[i][j]$ could represent the minimum number of operations needed to transform the first $i$ characters of string $A$ into the first $j$ characters of string $B$.

Next, let's consider how to design the state transition equation.

***

When $\text{word[i]}$ is equal to $\text{word[j]}$, we have:
$dp[i][j] = dp[i-1][j-1]$

But When $\text{word[i]}$ is not equal to $\text{word[j]}$, We need to categorize and discuss:

1. **Deleting** a character
   Since we are transforming from string $A$ to string $B$, deleting would mean removing a character from string $A$.
   $dp[i][j] = dp[i-1][j] + 1$
2. **Inserting** a character
   At this point, string $A$ is usually shorter than string $B$. To ensure the same ending character, we only need to consider the transformation situation assuming the <u>removal`[n.移除]`</u> of the last character from string $B$. This is because the last inserted character must be the one to ensure their similarity.
   $dp[i][j] = dp[i][j-1] + 1$
3. **Changing** one character to another
   At this point, usually, after the transformation, the two strings have the same length. It is only necessary to directly modify the last character.
   $dp[i][j] = dp[i-1][j-1] + 1$

We take the minimum value among the three cases mentioned above.

$$
dp[i][j] = \left\{
\begin{array}{l}
dp[i][j] = dp[i-1][j-1] & \text{If word[i] = word[j]}\\
\;\\
dp[i][j] = \min\{dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1
\} & \mathrm{If
\;word[i] \neq word[j]}\\
\end{array}
\right.
$$

Ultimately, we are left with the coding part, which is quite <u>straightforward`[adj.直戳了当的]`</u>.

But don't forget to initialize XD.
$dp[i][0] = dp[0][i] = i$

```cpp
#include <bits/stdc++.h>
using namespace std;

const int maxN = 2005;
int dp[maxN][maxN];

int main(int argc, char const *argv[])
{
    string A{}, B{};
    cin >> A >> B;

    int lenA = A.size(), lenB = B.size();

    //Don't forget to initialize.
    for (int i = 0; i <= lenA; i++)
        dp[i][0] = i;

    for (int i = 0; i <= lenB; i++)
        dp[0][i] = i;

    for (int i = 1; i <= lenA; i++)
    {
        for (int j = 1; j <= lenB; j++)
        {
            //Note that the initial index for strings is 0.
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
            }
        }
    }

    cout << dp[lenA][lenB] << endl;

    system("pause");
    return 0;
}
```
