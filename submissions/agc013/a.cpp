#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n <= 2) {
        cout << 1 << endl;
        return 0;
    }
    int ans = 1, now = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            if (now == 0) {
                now = 1;
            } else if (now == -1) {
                ans++, now = 0;
            }
        } else if (a[i] < a[i - 1]) {
            if (now == 0) {
                now = -1;
            } else if (now == 1) {
                ans++, now = 0;
            }
        }
    }
    cout << ans << endl;
}