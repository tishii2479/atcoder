#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b) { return std::min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n + 1);

    int cur = 0;
    seg.set(0, cur);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            cur++;
        else
            cur--;
        seg.set(i + 1, cur);
    }

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            if (s[l] == s[r]) continue;
            if (s[l] == '(' and s[r] == ')') {
                seg.apply(l + 1, r + 1, -2);
            } else {
                seg.apply(l + 1, r + 1, 2);
            }

            swap(s[l], s[r]);
        } else {
            if (seg.get(l) != seg.get(r + 1)) {
                cout << "No" << endl;
                continue;
            }
            if (seg.prod(l, r + 1) < seg.get(l)) {
                cout << "No" << endl;
                continue;
            }

            cout << "Yes" << endl;
        }
    }
}
