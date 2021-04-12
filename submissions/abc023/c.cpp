#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c, k, n;
    cin >> r >> c >> k >> n;
    vector<int> cnt_y(r, 0), cnt_x(c, 0);
    vector<int> y(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> y[i] >> x[i];
        x[i]--, y[i]--;
        cnt_y[y[i]]++;
        cnt_x[x[i]]++;
    }
    map<int, int> mp;
    for (int i = 0; i < c; i++) {
        mp[cnt_x[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < r; i++) {
        ans += mp[k - cnt_y[i]];
    }
    for (int i = 0; i < n; i++) {
        if (cnt_y[y[i]] + cnt_x[x[i]] == k)
            ans--;
        else if (cnt_y[y[i]] + cnt_x[x[i]] == k + 1)
            ans++;
    }
    cout << ans << endl;
}