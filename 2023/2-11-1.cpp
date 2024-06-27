#include <bits/stdc++.h>
using namespace std;
 
unordered_set<string> pool;
 
int main ()
{
    ios::sync_with_stdio(false);
    int n, m, ans = 0;
    cin >> n >> m;
    string s;
    while (n--)
    {
        cin >> s;
        pool.insert(s);
    }
    while (m--)
    {
        cin >> s;
        if (pool.find(s) != pool.end())
            ans++;
    }
    cout << ans << endl;
    return 0;
}