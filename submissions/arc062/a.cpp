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
    cin >> n;
    ll a, t;
    ll nowt = 1, nowa = 1;
    for (int i = 0; i < n; i++) {
        cin >> t >> a;
        ll dt = nowt / t;
        ll da = nowa / a;
        ll gc = max(dt, da);
        if (gc * a < nowa or gc * t < nowt)
            gc++;
        nowt = t * gc;
        nowa = a * gc;
    }
    cout << nowt + nowa << endl;
}