#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 1 << 30;
    for (int bit = 0; bit < (1 << (n - 1)); bit++) {
        vector<int> sep;
        for (int i = 0; i < n - 1; i++)
            if (bit & (1 << i))
                sep.push_back(i);
        int res = 0;
        int cur = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            cur |= a[i];
            if (j < sep.size() and i == sep[j]) {
                res ^= cur;
                j++;
                cur = 0;
            }
        }
        res ^= cur;
        ans = min(ans, res);
    }
    cout << ans << endl;
}