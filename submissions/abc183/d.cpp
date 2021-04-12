#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> total(210000, 0);
    for (int i = 0; i < n; i++) {
        ll s, t, p;
        cin >> s >> t >> p;
        total[s] += p;
        total[t] -= p;
    }
    for (int i = 0; i < 201000; i++) {
        total[i + 1] += total[i];
        if (total[i] > w) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}