#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<long long> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cnt[b[c[i] - 1]]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[a[i]];
    }

    cout << ans << endl;
}
