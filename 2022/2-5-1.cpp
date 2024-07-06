#include<bits/stdc++.h>

int n, k; 
int dp[110][10010];
 
int main() {
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= n; i++)
        dp[1][i] = i;
    for (int i = 1; i <= k; i++)
        dp[i][1] = 1;
    for (int i = 2; i <= k; i++)
        for (int j = 2; j <= n; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
    int ans = 1;
    while (dp[k][ans] < n)
        ans++;
    printf("%d\n", ans);
    return 0;
}