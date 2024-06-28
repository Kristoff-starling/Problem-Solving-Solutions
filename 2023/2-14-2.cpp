#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;

int n, k, x;
int a[MAXN], q[MAXN], head, tail;
long long sum[MAXN];

inline long long calc(int l, int r)
{
    long long ans = sum[r] - sum[l];
    if (r - l <= k)
        ans += 1ll * x * (r - l);
    else
        ans += 1ll * x * k - 1ll * x * (r - l - k);
    return ans;
}

int main ()
{
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    long long ans = 0;
    // <=k 的窗口
    head = tail = 1;
    q[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (i - q[head] > k)
            head++;
        ans = std::max(ans, calc(q[head], i));
        while (head <= tail && calc(q[tail], i) < calc(i, i))
            tail--;
        q[++tail] = i;
    }
    // >k 的窗口
    int maxi = 0;
    for (int i = k + 1; i <= n; i++)
    {
        ans = std::max(ans, calc(maxi, i));
        if (calc(maxi, i + 1) < calc(i - k, i + 1))
            maxi = i - k;
    }
    printf("%lld\n", ans);
    return 0;
}