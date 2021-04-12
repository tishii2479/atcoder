#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<pint> res;
int solve() {
    int n;
    cin >> n;
    vector<pint> ai(n);
    vector<int> b(n), p(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ai[i] = {a, i};
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    // who[i] := who has luggage i
    vector<int> who(n);
    for (int i = 0; i < n; i++)
        who[p[i]] = i;
    sort(ai.begin(), ai.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a = ai[i].first, idx = ai[i].second;
        if (idx == p[idx])
            continue;
        if (b[p[idx]] >= a)
            return -1;
        // swap
        int tmp = p[idx];
        swap(p[who[idx]], p[idx]);
        res.push_back({idx, who[idx]});
        who[tmp] = who[idx];
        who[idx] = idx;
        ans++;
    }
    return ans;
}
int main() {
    int ans = solve();
    cout << ans << endl;
    if (ans != -1)
        for (auto r : res)
            cout << r.first + 1 << " " << r.second + 1 << endl;
}