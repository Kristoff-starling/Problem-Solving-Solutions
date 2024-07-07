#include <bits/stdc++.h>
#include "Core.h"

int check(int seed, int n, int A, int B);

int seed, n;
std::mt19937 mt(time(nullptr));

int main ()
{
    scanf("%d%d", &seed, &n);
    for (;;)
    {
        int cur = mt() % n;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (i != cur)
                cnt += (check(seed, n, cur, i) == 0);
        if (cnt >= (n - 1) / 2)
        {
            printf("%d\n", cur);
            return 0;
        }
    }
    return 0;
}