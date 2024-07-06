#include <bits/stdc++.h>

const int MAXN = 520;

int n, m;
int v[MAXN], w[MAXN], W;

// dp[i][j] 表示当前考虑到第 i 个物品，物品总价值为 j 的情况下，最少需要多少体积
// 为了优化存储空间，省去第一维，dp[i][...] 复用 dp[i-1][...] 的数组，具体见代码
int dp[1000010];

int main ()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", v + i, w + i);
        W += w[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= W; i++)
        dp[i] = m + 10;
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= 0; j--)
            // 倒序 dp，保证 dp[j - w[i]] 的值是上一层的
            if (j >= w[i] && dp[j - w[i]] < m)
                dp[j] = std::min(dp[j], dp[j - w[i]] + v[i]);
    int ans = W;
    while (dp[ans] > m)
        ans--;
    printf("%d\n", ans);
    return 0;
}