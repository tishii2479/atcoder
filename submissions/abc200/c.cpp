#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> cnt(200, 0);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int val = a[i] % 200;
        ans += cnt[val];
        cnt[val]++;
    }

    cout << ans << endl;
}
