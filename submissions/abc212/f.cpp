#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using ll = long long;

struct S {
    // type
    // 0 = start, 1 = end, 2 = x, 3 = z
    int type, idx, from, to;
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    map<ll, vector<S>> mp;

    for (int i = 0; i < m; i++) {
        int a, b;
        ll s, t;
        cin >> a >> b >> s >> t;
        a--, b--;

        S d;
        d.type = 0, d.from = a, d.to = b, d.idx = i;
        mp[s * 2 + 1].push_back(d);

        d.type = 1;
        mp[t * 2 + 1].push_back(d);
    }

    vector<int> cur_town(n, -1);
    vector<int> cur_path(m, -1);
    vector<pair<int, int>> cur(q, {-1, -1});
    vector<pair<int, int>> res(q);
    atcoder::dsu uf(q);

    for (int i = 0; i < q; i++) {
        res[i].second = -1;

        ll x, y, z;
        cin >> x >> y >> z;
        y--;

        S d;
        d.type = 2;
        d.from = y;
        d.idx = i;
        mp[x * 2].push_back(d);

        d.type = 3;
        mp[z * 2].push_back(d);
    }

    for (auto p : mp) {
        vector<S> v = p.second;

        sort(v.begin(), v.end(), [](S a, S b) {
            return a.type > b.type;
        });

        for (auto s : v) {
            if (s.type == 0) {
                // start
                int group = cur_town[s.from];
                if (group == -1) continue;
                cur_town[s.from] = -1;
                cur_path[s.idx] = group;
                cur[group] = {s.from, s.to};
            } else if (s.type == 1) {
                // end
                int group = cur_path[s.idx];
                if (group == -1) continue;
                cur_path[s.idx] = -1;
                if (cur_town[s.to] != -1) uf.merge(group, cur_town[s.to]);
                group = uf.leader(group);
                cur_town[s.to] = group;
                cur[group] = {s.to, -1};
            } else if (s.type == 2) {
                // x
                int group = cur_town[s.from];
                if (group != -1) uf.merge(group, s.idx);
                group = uf.leader(s.idx);
                cur_town[s.from] = group;
                cur[group] = {s.from, -1};
            } else {
                // z
                res[s.idx] = cur[uf.leader(s.idx)];
            }
        }

        // for (int i = 0; i < q; i++) {
        //     cout << cur[i].first << " " << cur[i].second << endl;
        // }
    }

    for (int i = 0; i < q; i++) {
        if (res[i].second != -1) {
            cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
        } else {
            cout << res[i].first + 1 << endl;
        }
    }
}
