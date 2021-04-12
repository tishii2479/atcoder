#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int op(int l, int r) { return max(l, r); }
int e() { return 0; }
int main() {
    const int N = 510000;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    segtree<int, op, e> seg(N);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int left = max(0, a - k), right = min(N, a + k + 1);
        int val = seg.prod(left, right);
        seg.set(a, val + 1);
    }
    cout << seg.prod(0, N) << endl;
}