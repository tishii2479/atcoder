#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 40;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> sushi(110000);
    for (int i = 0; i < n; i++) {
        ll t;
        ll d;
        cin >> t >> d;
        t--;
        sushi[t].push_back(d);
    }
    for (int i = 0; i < 110000; i++) {
        sort(sushi[i].begin(), sushi[i].end(), greater<ll>());
        if (sushi[i].empty())
            sushi[i].push_back(-INF);
    }
    sort(sushi.begin(), sushi.end(), [&](vector<ll> a, vector<ll> b) { return a[0] > b[0]; });
    priority_queue<ll, vector<ll>> pq;
    ll cur = 0;
    for (int i = 0; i < k; i++) {
        cur += sushi[i][0];
        for (int j = 1; j < sushi[i].size(); j++)
            pq.push(sushi[i][j]);
    }
    for (int i = k; i < 110000; i++)
        for (int j = 0; j < sushi[i].size(); j++)
            pq.push(sushi[i][j]);
    ll ans = cur + k * k;
    for (ll x = k - 1; x >= 1; x--) {
        ll v = sushi[x][0];
        ll w = pq.top();
        if (v < w) {
            cur -= v;
            cur += w;
            pq.pop();
            pq.push(v);
        }
        ans = max(ans, cur + x * x);
    }
    cout << ans << endl;
}