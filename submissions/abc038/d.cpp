#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }
int main() {
    const int N = 110000;
    int n;
    cin >> n;
    vector<vector<int>> box(N);
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        box[h].push_back(w);
    }
    segtree<S, op, e> seg(N);
    for (int i = 0; i < N - 1; i++) {
        sort(box[i].rbegin(), box[i].rend());
        for (int j = 0; j < box[i].size(); j++) {
            int val = seg.prod(0, box[i][j]);
            seg.set(box[i][j], val + 1);
        }
    }
    cout << seg.all_prod() << endl;
}