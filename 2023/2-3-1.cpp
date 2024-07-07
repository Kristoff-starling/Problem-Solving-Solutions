#include <bits/stdc++.h>

int main ()
{
    // sum: 当前前缀和
    // minsum: 之前所有的前缀和中最小的前缀和
    int n, x, sum = 0, minsum = 0, ans = -1e9;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        sum += x;
        ans = std::max(ans, sum - minsum);
        minsum = std::min(minsum, sum);
    }
    printf("%d\n", ans);
    return 0;
}