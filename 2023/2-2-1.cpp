#include <bits/stdc++.h>

const int MOD = 998244353;
const int MAXN = 3000;

int n, m;

int quick_pow(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return res;
}

// fac[i] = 1 * 2 * ... * i, ifac[i] = fac[i] 的逆元
int fac[MAXN], ifac[MAXN];
void init_C()
{
    fac[0] = 1;
    for (int i = 1; i <= n + m; i++)
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    ifac[n + m] = quick_pow(fac[n + m], MOD - 2);
    for (int i = n + m - 1; i >= 0; i--)
        ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}

int C(int n, int m)
{
    return 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int main ()
{
    scanf("%d%d", &n, &m);
    init_C();
    printf("%d\n", C(n + m - 1, m - 1));
    return 0;
}