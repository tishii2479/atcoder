#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;

int main() {
    using mint = modint1000000007;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.push_back(0);
    sort(a.begin(), a.end());
    mint ans = 1;
    for (int i = 0; i < n; i++) ans *= a[i + 1] - a[i] + 1;
    cout << ans.val() << endl;
}
