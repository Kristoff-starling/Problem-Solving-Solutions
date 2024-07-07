#include <bits/stdc++.h>

const int MAXN = 520;
const int MOD = 998244353;

int n, m;
int S[MAXN][MAXN];

int main ()
{
    scanf("%d%d", &n, &m);
    S[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j] % MOD) % MOD;
    printf("%d\n", S[n][m]);
    return 0;
}