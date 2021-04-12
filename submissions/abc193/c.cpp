#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
// エラトステネス
vector<bool> isUsed(110000, false);
int main() {
    ll n;
    cin >> n;
    ll cnt = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (isUsed[i])
            continue;
        ll t = i;
        ll c = 0;
        while (t * i <= n) {
            t *= i;
            if (t < 110000)
                isUsed[t] = true;
            c++;
        }
        cnt += c;
    }
    cout << n - cnt << endl;
}