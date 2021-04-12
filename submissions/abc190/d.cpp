#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n;
    cin >> n;
    set<pll> st;
    // (b + a) * (b - a) = 2N
    for (ll i = 1; i * i < 2 * n; i++) {
        if ((2 * n) % i == 0) {
            ll j = (2 * n) / i;
            if (i % 2 == j % 2)
                continue;
            ll a = (j - i + 1) / 2;
            ll b = (i + j - 1) / 2;
            st.insert({a, b});
        }
    }
    cout << st.size() * 2 << endl;
}