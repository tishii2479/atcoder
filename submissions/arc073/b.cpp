#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
ll n, W;
ll ans = 0;
vector<ll> vec[4];
ll length[4];
ll weight[4];
ll type;
void saiki(ll curv, ll curw, int n) {
    if (n == type) {
        // cout << n << " " << curv << " " << curw << endl;
        if (curw > W)
            return;
        ans = max(ans, curv);
        return;
    }
    saiki(curv, curw, n + 1);
    for (int i = 0; i < length[n]; i++) {
        curv += vec[n][i];
        curw += weight[n];
        saiki(curv, curw, n + 1);
    }
}
int main() {
    cin >> n >> W;
    map<int, vector<ll>> mp;
    for (ll i = 0; i < n; i++) {
        ll w, v;
        cin >> w >> v;
        mp[w].push_back(v);
    }
    type = 0;
    for (auto m : mp) {
        vec[type] = m.second;
        weight[type] = m.first;
        length[type] = vec[type].size();
        sort(vec[type].begin(), vec[type].end(), greater<ll>());
        type++;
    }
    saiki(0, 0, 0);
    cout << ans << endl;
}