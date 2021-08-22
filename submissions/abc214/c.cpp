#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n;
    cin >> n;
    vector<ll> s(n);
    vector<pair<ll, int>> t(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        cin >> t[i].first;
        t[i].second = i;
    }

    const ll INF = 1LL << 60;
    vector<ll> ans(n, INF);
    for (int i = 0; i < n; i++) ans[i] = t[i].first;

    sort(t.begin(), t.end());

    for (auto p : t) {
        ll time = p.first;
        int idx = p.second;

        if (time > ans[idx]) continue;
        ans[idx] = time;

        while (ans[(idx + 1) % n] > ans[idx] + s[idx]) {
            ans[(idx + 1) % n] = ans[idx] + s[idx];
            idx++;
            idx %= n;
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << endl;
}
