#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    ll n, m;
    cin >> n >> m;
    map<ll, vector<ll>> black;
    for (int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        black[x].push_back(y);
    }

    set<ll> cur;
    cur.insert(n);

    for (auto m : black) {
        auto v = m.second;
        sort(v.begin(), v.end());
        int now = 0;
        vector<ll> add, sub;
        for (ll e : v) {
            if (cur.find(e) != cur.end())
                sub.push_back(e);
            if (cur.find(e - 1) != cur.end() and e <= 2 * n)
                add.push_back(e);
            if (cur.find(e + 1) != cur.end() and e >= 0)
                add.push_back(e);
        }
        // for (ll e : cur) {
        //     if (binary_search(v.begin(), v.end(), e)) {
        //         sub.push_back(e);
        //     }
        //     if (binary_search(v.begin(), v.end(), e + 1) and e + 1 <= 2 * n) {
        //         add.push_back(e + 1);
        //     }
        //     if (binary_search(v.begin(), v.end(), e - 1) and e - 1 >= 0) {
        //         add.push_back(e - 1);
        //     }
        // }
        for (ll e : sub) cur.erase(e);
        for (ll e : add) cur.insert(e);
    }

    cout << cur.size() << endl;
}
