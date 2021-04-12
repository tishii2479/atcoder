#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
const int inf = 1 << 30;
const int N = 2000000;
using S = int;
S op(int a, int b) { return min(a, b); }
S e() { return inf; }
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    segtree<S, op, e> seg(v);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = inf;
    vector<int> cnt(N, 0);
    for (int i = 0; i < m; i++) {
        seg.set(a[i], inf);
        cnt[a[i]]++;
    }
    ans = seg.prod(0, N);
    for (int i = m; i < n; i++) {
        cnt[a[i - m]]--;
        if (cnt[a[i - m]] == 0) seg.set(a[i - m], a[i - m]);
        seg.set(a[i], inf);
        cnt[a[i]]++;
        ans = min(ans, seg.prod(0, N));
    }
    cout << ans << endl;
}