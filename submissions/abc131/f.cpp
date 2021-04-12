#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    const int N = 110000;
    ll n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    for (int i = 0; i < n; i++)
        cin >> xy[i].first >> xy[i].second;
    vector<pair<int, int>> xcnt[N];
    vector<pair<int, int>> ycnt[N];
    for (int i = 0; i < n; i++) {
        xcnt[xy[i].first].push_back({xy[i].second, i});
        ycnt[xy[i].second].push_back({xy[i].first, i});
    }
    ll ans = 0;
    vector<bool> seen(n, false);
    for (ll i = 0; i < n; i++) {
        if (seen[i])
            continue;
        queue<pair<pair<int, int>, int>> que;
        que.push({xy[i], i});
        set<int> stx, sty;
        while (que.empty() == false) {
            auto p = que.front();
            que.pop();
            ll x = p.first.first, y = p.first.second, idx = p.second;
            if (seen[idx])
                continue;
            seen[idx] = true;
            stx.insert(x), sty.insert(y);
            for (auto py : xcnt[x]) {
                que.push({{x, py.first}, py.second});
            }
            for (auto px : ycnt[y]) {
                que.push({{px.first, y}, px.second});
            }
        }
        ans += (ll)stx.size() * sty.size();
    }
    cout << ans - n << endl;
}