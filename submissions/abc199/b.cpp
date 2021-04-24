#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 1; i <= 1000; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] <= i and i <= b[j]) cnt++;
        }
        if (cnt == n) ans++;
    }

    cout << ans << endl;
}
