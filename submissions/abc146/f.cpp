#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
template <typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;
    int sz;
    vector<Monoid> seg;
    const F f;        // 評価関数
    const Monoid M1;  // 単位元
    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while (sz < n)
            sz <<= 1;
        seg.assign(2 * sz, M1);
    }
    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }
    void build() {
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }
    // to k, set value x
    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }
    // get [a, b)
    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1)
                L = f(L, seg[a++]);
            if (b & 1)
                R = f(seg[--b], R);
        }
        return f(L, R);
    }
    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }
    template <typename C>
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while (a < sz) {
            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if (check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }
    template <typename C>
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, seg[1])))
                return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt))
                    return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }
    template <typename C>
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(seg[1], R)))
                return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt))
                    return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};
int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    SegmentTree<int> seg(
        n + 1, [](int a, int b) { return min(a, b); }, inf);
    seg.update(n, 0);
    int l = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            l++;
            if (l >= m) {
                cout << -1 << endl;
                return 0;
            }
            continue;
        }
        l = 0;
        int right = min(i + m + 1, n + 1);
        int val = seg.query(i + 1, right);
        seg.update(i, val + 1);
    }
    int cur = 0;
    int now = 0;
    while (now != n) {
        while (seg[now] == seg[cur] or seg[cur] == inf)
            cur++;
        cout << cur - now << " ";
        now = cur;
    }
    cout << endl;
}