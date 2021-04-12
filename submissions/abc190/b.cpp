#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, s, d;
    cin >> n >> s >> d;
    vector<ll> x(n);
    vector<ll> y(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (ll i = 0; i < n; i++) {
        if (x[i] < s and y[i] > d) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}