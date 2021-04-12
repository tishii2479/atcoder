#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<int> edges[110000];
vector<ll> invfact(110000, -1);
vector<ll> fact(110000, -1);
ll fac(ll x) {
    if (fact[x] != -1)
        return fact[x];
    ll res = 1;
    for (ll i = 1; i <= x; i++) {
        res *= i;
        res %= MOD;
    }
    return fact[x] = res;
}
ll modpow(ll m, ll n) {
    if (n == 1)
        return m;
    if (n == 0)
        return 1;
    ll res;
    ll t = modpow(m, n / 2);
    ll tmp;
    if (n % 2 == 0) {
        tmp = (t * t) % MOD;
    } else {
        tmp = (((t * t) % MOD) * m) % MOD;
    }
    return tmp;
}
ll inv(ll a) {
    return modpow(a, MOD - 2);
}
int main() {
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // if 0 is seen, cnt will be 0
    ll ans = k;
    queue<int> q;
    vector<bool> seen(n, false);
    q.push(0);
    while (q.empty() == false) {
        int v = q.front();
        q.pop();
        seen[v] = true;
        int ps = ((v == 0) ? 0 : 1);
        int c = edges[v].size() - ps;  // child count
        if (k < c + 1 + ps) {
            cout << 0 << endl;
            return 0;
        }
        ans *= ((fac(k - ps - 1) * inv(fac(k - ps - c - 1))) % MOD);
        ans = (ans + MOD) % MOD;
        for (int u : edges[v]) {
            if (seen[u] == false)
                q.push(u);
        }
    }
    cout << ans << endl;
}