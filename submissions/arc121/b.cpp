#include <bits/stdc++.h>
using namespace std;

int idx(char c) {
    if (c == 'R') {
        return 0;
    } else if (c == 'B') {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    using ll = long long;
    int n;
    cin >> n;
    n *= 2;
    vector<pair<ll, char>> ac(n);
    vector<int> cnt(3);
    vector<ll> a[3];
    for (int i = 0; i < n; i++) {
        cin >> ac[i].first >> ac[i].second;
        cnt[idx(ac[i].second)]++;
        a[idx(ac[i].second)].push_back(ac[i].first);
    }

    sort(ac.begin(), ac.end());
    for (int i = 0; i < 3; i++) sort(a[i].begin(), a[i].end());

    vector<int> v;
    for (int i = 0; i < 3; i++)
        if (cnt[i] % 2 == 1) v.push_back(i);

    if (v.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    assert(v.size() == 2);

    vector<pair<ll, char>> new_ac;

    for (int i = 0; i < n; i++) {
        int color = idx(ac[i].second);
        if (color == v[0] or color == v[1]) {
            new_ac.push_back(ac[i]);
        }
    }

    ll ans = 1LL << 60;
    for (int i = 0; i + 1 < new_ac.size(); i++) {
        if (new_ac[i].second == new_ac[i + 1].second) continue;
        ans = min(ans, new_ac[i + 1].first - new_ac[i].first);
    }

    int other = 3 - v[0] - v[1];

    vector<pair<ll, pair<int, int>>> cand;
    for (int i = 0; i + 1 < n; i++) {
        if (idx(ac[i].second) != other and idx(ac[i + 1].second) != other) continue;
        if (idx(ac[i].second) == idx(ac[i + 1].second)) continue;
        cand.push_back({ac[i + 1].first - ac[i].first,
                        {min(idx(ac[i].second), idx(ac[i + 1].second)),
                         max(idx(ac[i].second), idx(ac[i + 1].second))}});
    }

    sort(cand.begin(), cand.end());

    if (cand.size() >= 2) {
        ll ans2 = cand[0].first;
        pair<int, int> best = cand[0].second;
        int cur = 1;
        while (best == cand[cur].second) cur++;
        ans2 += cand[cur].first;

        ans = min(ans, ans2);
    }

    cout << ans << endl;
}
