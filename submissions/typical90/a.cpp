#include <bits/stdc++.h>
using namespace std;

int main() {
    const int inf = 1 << 30;
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n + 2);
    a[0] = 0;
    for (int i = 0; i < n; i++) cin >> a[i + 1];
    a[n + 1] = l;
    n = a.size();
    int left = 0, right = inf;
    while (right - left > 1) {
        int cnt = 0, cur = 0;
        int m = (left + right) / 2;

        for (int i = 0; i + 1 < n; i++) {
            int unit = a[i + 1] - a[i];
            cur += unit;
            if (cur >= m) {
                cnt++;
                cur = 0;
            }
        }

        if (cnt <= k)
            right = m;
        else
            left = m;
    }
    cout << left << endl;
}
