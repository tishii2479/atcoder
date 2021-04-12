#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    int r = 0;
    int cur = 0;
    for (int l = 0; l < n; l++) {
        while (r < n and (cur ^ a[r]) == (cur + a[r])) {
            cur += a[r];
            r++;
        }
        ans += r - l;
        if (l == r)
            r++;
        else
            cur -= a[l];
    }
    cout << ans << endl;
}