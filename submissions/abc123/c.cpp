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
    ll n;
    ll a[5];
    cin >> n;
    ll k = 0;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        k = max(k, (n + a[i] - 1) / a[i]);
    }
    cout << k + 4 << endl;
}