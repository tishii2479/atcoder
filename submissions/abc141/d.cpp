#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<ll, vector<ll>> pq;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < m; i++) {
        ll a = pq.top();
        pq.pop();
        a /= 2;
        pq.push(a);
    }
    ll ans = 0;
    while (!pq.empty()) {
        ll a = pq.top();
        pq.pop();
        ans += a;
    }
    cout << ans << endl;
}