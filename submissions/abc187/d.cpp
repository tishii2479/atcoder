#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<pll> data;
    vector<pll> ab;
    ll acnt = 0;
    ll bcnt = 0;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        acnt += a;
        data.push_back({a, b});
        ab.push_back({a * 2 + b, i});
    }
    sort(ab.begin(), ab.end(), greater<pll>());
    int now = 0;
    while (bcnt <= acnt) {
        bcnt += data[ab[now].second].second + data[ab[now].second].first;
        acnt -= data[ab[now].second].first;
        now++;
        // cout << bcnt << " " << acnt << endl;
    }
    cout << now << endl;
}