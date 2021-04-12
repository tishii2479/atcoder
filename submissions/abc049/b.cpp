#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int main() {
    int n, k, l;
    cin >> n >> k >> l;
    dsu uf1(n), uf2(n);
    for (int i = 0; i < k; i++) {
        int p, q;
        cin >> p >> q;
        p--, q--;
        uf1.merge(p, q);
    }
    for (int i = 0; i < l; i++) {
        int r, s;
        cin >> r >> s;
        r--, s--;
        uf2.merge(r, s);
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int root = uf1.leader(i);
        mp[root].push_back(i);
    }
    vector<int> res(n);
    for (auto m : mp) {
        vector<int> v = m.second;
        map<int, int> cnt;
        for (int u : v) {
            cnt[uf2.leader(u)]++;
        }
        for (int u : v) {
            res[u] = cnt[uf2.leader(u)];
        }
    }
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}