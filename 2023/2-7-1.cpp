#include <bits/stdc++.h>
#define MOD 998244353
 
int n;
std::string a[50010];
 
int main ()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    sort(a + 1, a + n + 1, [](std::string x, std::string y) { return x + y >= y + x; });
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < int(a[i].size()); j++)
            ans = (1ll * ans * 10 + (a[i][j] - '0')) % MOD;
    std::cout << ans << '\n';
    return 0;
}