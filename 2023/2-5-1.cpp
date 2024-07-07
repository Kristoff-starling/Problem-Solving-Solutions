#include <bits/stdc++.h>

const int MOD = 998244353;

int n, dp[5010];

int main() {
    scanf("%d", &n);
	dp[1] = 0; dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = 1ll * (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
	}
    printf("%d\n", dp[n]);
    return 0;
}