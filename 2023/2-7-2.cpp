#include <bits/stdc++.h>

const int MAXN = 100010;

int n, k;
int a[MAXN];

bool check(int gap)
{
    int cnt = 0, cur = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - cur < gap)
            cnt++;
        else
            cur = a[i];
    }
    return cnt <= k;
}

int main ()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    int l = 1, r = a[n] - a[1], mid, ans = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1; else r = mid - 1;
    }
    std::cout << ans << '\n';
    return 0;
}