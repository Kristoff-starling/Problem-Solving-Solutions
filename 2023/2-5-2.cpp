#include <bits/stdc++.h>

const int MAXN = 1010;

int n;
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int v[MAXN], tmp[MAXN], v1[MAXN], v2[MAXN];

std::mt19937 mt(time(nullptr));

void mul(int a[][MAXN], int b[], int c[])
{
    for (int i = 1; i <= n; i++)
    {
        c[i] = 0;
        for (int j = 1; j <= n; j++)
            c[i] += a[i][j] * b[j];
    }
}

int main ()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &b[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    int T = 20;
    while (T--)
    {
        for (int i = 1; i <= n; i++)
            v[i] = (mt() & 1 ? 1 : 0);
        mul(b, v, tmp);
        mul(a, tmp, v1);
        mul(c, v, v2);
        for (int i = 1; i <= n; i++)
            if (v1[i] != v2[i])
            {
                puts("No");
                return 0;
            }
    }
    puts("Yes");
    return 0;
}