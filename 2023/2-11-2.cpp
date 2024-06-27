#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    long long target;
    cin >> n >> target;
    map<long long, int>mp;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (mp.count(target - x)) {
            cout << i << " " << mp[target - x] << endl;
            return 0;
        }
        mp.insert({ x,i });
    }
    return 0;
}