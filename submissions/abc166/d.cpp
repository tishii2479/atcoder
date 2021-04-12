#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll x;
    cin >> x;
    for (ll a = -1000; a <= 1000; a++) {
        for (ll b = -1000; b <= 1000; b++) {
            if (pow(a, 5) - pow(b, 5) == x) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}