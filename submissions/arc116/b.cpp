#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
int main() {
    using mint = modint998244353;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    mint cur = 0;
    mint ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cur * a[i] + a[i] * a[i];
        cur *= 2;
        cur += a[i];
    }
    cout << ans.val() << endl;
}