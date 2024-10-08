#include <bits/stdc++.h>
using namespace std;

class mint
{
private:
    int64_t val = 0;

    int64_t fastPow(int64_t a, int64_t n, int64_t m) {
        int64_t ans{1};
        while (n) {
            if (n&1) ans = (ans*a) % m;
            a = (a*a) % m;
            n >>= 1;
        }
        return ans;
    }

    int64_t inv(int64_t a, int64_t m) {
        return fastPow(a, m-2, m);
    } 

public:
    static int64_t mod;

    mint() {}
    mint(int num) : val(num % mod) {
        mod = 1e9+7;
    }
    mint(int64_t num) : val(num % mod) {
        mod = 1e9+7;
    }
    mint(mint& other) : val(other.val % mod) {
        mod = 1e9+7;
    }

    mint& operator+(mint& other) {
        val = (val % mod + other.val % mod + mod) % mod;
        return *this;
    }

    mint& operator-(mint& other) {
        val = (val % mod - other.val % mod + mod) % mod;
        return *this;
    }

    mint& operator*(mint& other) {
        val = val % mod * (other.val % mod) % mod;
        return *this;
    }

    mint& operator/(mint& other) {
        val = val % mod * (inv(other.val, mod) % mod) % mod;
        return *this;
    }

    mint& operator+=(mint& other) {
        val = (val % mod + other.val % mod + mod) % mod;
        return *this;
    }

    mint& operator-=(mint& other) {
        val = (val % mod - other.val % mod + mod) % mod;
        return *this;
    }

    mint& operator*=(mint& other) {
        val = val % mod * (other.val % mod) % mod;
        return *this;
    }

    mint& operator/=(mint& other) {
        val = val % mod * (inv(other.val, mod) % mod) % mod;
        return *this;
    }

    operator int() {
        return (int)val;
    }

    operator long long() {
        return (long long)val;
    }

    friend ostream& operator<<(ostream& out, mint& num) {
        out << num.val;
        return out;
    }

    friend istream& operator>>(istream& in, mint& num) {
        in >> num.val;
        return in;
    }
};
int64_t mint::mod = 1e9+7;

signed main()
{
    mint a = 1829753921753129;

    cout << a << endl;


    system("pause");
    return 0;
}