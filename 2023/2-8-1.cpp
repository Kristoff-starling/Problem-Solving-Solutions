#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;

int r, c, k;
int n;
int X[MAXN], Y[MAXN];
std::map<int, int> cntX, cntY;
int cx[MAXN], cy[MAXN], ax, ay;

int main ()
{
    scanf("%d%d%d%d", &r, &c, &k, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", X + i, Y + i);
        cntX[X[i]]++;
        cntY[Y[i]]++;
    }
    for (std::map<int, int>::iterator iter = cntX.begin(); iter != cntX.end(); iter++)
        cx[iter->second]++;
    for (std::map<int, int>::iterator iter = cntY.begin(); iter != cntY.end(); iter++)
        cy[iter->second]++;
    ax = int(cntX.size()); ay = int(cntY.size());
    long long ans = 0;
    for (int i = 1; i <= k - 1; i++)
        ans += 1ll * cx[i] * cy[k - i];   
    ans += 1ll * cx[k] * (c - ay);
    ans += 1ll * cy[k] * (r - ax);
    for (int i = 1; i <= n; i++)
    {
        if (cntX[X[i]] + cntY[Y[i]] == k) ans--;
        if (cntX[X[i]] + cntY[Y[i]] == k + 1) ans++;
    }
    printf("%d\n", ans);
    return 0;
}