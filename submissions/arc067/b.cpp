#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    ll ans = 0;
    cin >> x[0];
    for (int i = 1; i < n; i++) {
        cin >> x[i];
        ans += min(a * (x[i] - x[i - 1]), b);
    }
    cout << ans << endl;
}