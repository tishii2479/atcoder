#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, k;
    cin >> n >> k;
    map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    for (auto m : mp) {
        k -= m.second;
        if (k <= 0) {
            cout << m.first << endl;
            return 0;
        }
    }
}