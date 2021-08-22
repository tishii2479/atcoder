#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;
    for (int i = 0; i < 29; i++) {
        vector<int> v(n);
        for (int j = 0; j < n; j++) v[j] = b[j] % (1 << (i + 1));
        sort(v.begin(), v.end());

        long long cnt = 0;
        int mask = (1 << i);

        for (int j = 0; j < n; j++) {
            int val = a[j] % (1 << (i + 1));
            int left = lower_bound(v.begin(), v.end(), mask - val) - v.begin();
            int right = lower_bound(v.begin(), v.end(), mask * 2 - val) - v.begin();
            cnt += right - left;

            int left2 = lower_bound(v.begin(), v.end(), mask * 3 - val) - v.begin();
            int right2 = lower_bound(v.begin(), v.end(), mask * 4 - val) - v.begin();
            cnt += right2 - left2;
        }

        ans |= (1 << i) * (cnt % 2);
    }
    cout << ans << endl;
}
