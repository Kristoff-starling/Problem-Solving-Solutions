#include <bits/stdc++.h>

int main ()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        ans = std::max(ans, x * y);
    }
    printf("%d\n", ans);
    return 0;
}