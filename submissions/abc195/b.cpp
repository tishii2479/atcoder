#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll a, b, w;
    cin >> a >> b >> w;
    w *= 1000;
    ll mx = w / a;
    ll mn = (w + b - 1) / b;
    if (mn > mx) {
        cout << "UNSATISFIABLE" << endl;
        return 0;
    }
    cout << mn << " " << mx << endl;
}