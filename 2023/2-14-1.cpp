#include <bits/stdc++.h>

const int MAXN = 1e6 + 10;

char s[MAXN], t[2000];
int n, m, nxt[MAXN][27], dp[2000][2000];

int main ()
{
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1); m = strlen(t + 1);
    for (int i = 1; i <= 26; i++)
        nxt[n + 1][i] = n + 1;
    // nxt[i][ch] 表示从 s[i] 开始 (不包括 s[i]) 第一个字符 ch 的位置
    for (int i = n; i >= 0; i--)
    {
        for (int j = 1; j <= 26; j++)
            nxt[i][j] = nxt[i + 1][j];
        if (i != n)
            nxt[i][s[i + 1] - 'a' + 1] = i + 1;
    }
    // dp[i][j] 表示考虑 t[1...i]，想要获得长度为 j 的公共子序列，至少需要 s 多长的前缀
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            dp[i][j] = n + 1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = std::min(dp[i - 1][j], nxt[dp[i - 1][j - 1]][t[i] - 'a' + 1]);
    int ans = m;
    while (dp[m][ans] > n)
        ans--;
    printf("%d\n", ans);
    return 0;
}