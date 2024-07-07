#include <bits/stdc++.h>

int n, r;
double p[100], pi[100];

int main ()
{
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++)
        scanf("%lf", p + i);
    double pe = 0;
    for (int i = 1; i <= n; i++)
        pi[i] = 0;
    for (int Mask = 0; Mask <= (1 << n) - 1; Mask++)
    {
        double pp = 1;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (Mask >> (i - 1) & 1)
            {
                pp *= p[i];
                cnt++;
            }
            else
                pp *= (1.0 - p[i]);
        if (cnt == r)
            pe += pp;
        for (int i = 1; i <= n; i++)
            if (cnt == r && (Mask >> (i - 1) & 1))
                pi[i] += pp;
    }
    for (int i = 1; i <= n; i++)
        printf("%.4lf\n", pi[i] / pe);
    return 0;
}