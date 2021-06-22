#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, long long> mp;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (i - mp[a[i]]);
        mp[a[i]]++;
    }

    cout << ans << endl;
}
