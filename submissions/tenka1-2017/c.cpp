#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll N;
    cin >> N;
    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 1; n <= 3500; n++) {
            ll b = 4 * h * n - N * n - N * h;
            if (b <= 0)
                continue;
            ll a = N * n * h;
            if (a % b == 0) {
                ll w = a / b;
                cout << h << " " << n << " " << w << endl;
                return 0;
            }
        }
    }
}