#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using S = long long;
S op(S a, S b) { return a + b; }
S e() { return 0; }
ll all = 0;
bool ok(ll value) {
    if (all % 2 == 0) {
        return value <= all / 2 - 1;
    } else {
        return value <= all / 2;
    }
}
int main() {
    int q;
    cin >> q;
    vector<pair<int, pair<ll, ll>>> query(q);
    vector<ll> all_a;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            ll a, b;
            cin >> a >> b;
            query[i] = {1, {a, b}};
            all_a.push_back(a);
        } else {
            query[i] = {2, {0, 0}};
        }
    }
    sort(all_a.begin(), all_a.end());
    map<ll, int> mp;
    const int N = all_a.size();
    for (int i = 0; i < N; i++) mp[all_a[i]] = i;
    segtree<S, op, e> seg1(N), seg2(N);
    ll b_sum = 0;
    for (int i = 0; i < q; i++) {
        int t = query[i].first;
        if (t == 1) {
            ll a = query[i].second.first, b = query[i].second.second;
            b_sum += b;
            int idx = mp[a];
            int val = seg1.get(idx);
            val++;
            all++;
            seg1.set(idx, val);
            seg2.set(idx, a * val);
        } else {
            ll res = b_sum;
            ll median_index = seg1.max_right(0, ok);
            ll median_sum = seg2.get(median_index);
            ll median_cnt = seg1.get(median_index);
            ll left_sum = seg2.prod(0, median_index);
            ll right_sum = seg2.prod(median_index + 1, N);
            ll left_cnt = seg1.prod(0, median_index);
            ll right_cnt = seg1.prod(median_index + 1, N);
            ll median = median_sum / median_cnt;
            res += right_sum - left_sum + (left_cnt - right_cnt) * median;
            cout << median << " " << res << endl;
        }
    }
}