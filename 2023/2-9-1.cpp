#include <bits/stdc++.h>

const int MAXN = 5e4 + 10;

int n;
int a[MAXN], b[MAXN], pos[MAXN], ans[MAXN], D;

void dfs(int l1, int r1, int l2, int r2, int depth)
{
    D = std::max(D, depth);
    ans[depth] = a[l1];
    int rt = l1 + 1, L = l2;
    while (rt <= r1)
    {
        int rt2 = pos[a[rt]];
        dfs(rt, rt + (rt2 - L), L, rt2, depth + 1);
        rt += (rt2 - L + 1);
        L = rt2 + 1;
    }
}

int main ()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", b + i);
        pos[b[i]] = i;
    }
    dfs(1, n, 1, n, 1);
    for (int i = 1; i <= D; i++)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}