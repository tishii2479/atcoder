#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve() {
    int n;
    cin >> n;
    vector<pair<ll, int>> left, right;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int k;
        ll l, r;
        cin >> k >> l >> r;
        sum += min(l, r);
        if (l >= r) {
            left.push_back({l - r, k});
        } else {
            right.push_back({r - l, n - k});
        }
    }
    sort(left.begin(), left.end(), greater<pair<ll, int>>());
    sort(right.begin(), right.end(), greater<pair<ll, int>>());
    set<int> st;
    for (int i = 1; i <= left.size(); i++) st.insert(i);
    for (int i = 0; i < left.size(); i++) {
        auto it = st.upper_bound(left[i].second);
        int val;
        if (it == st.begin()) {
            val = *st.rbegin();
        } else {
            it--;
            val = *it;
            sum += left[i].first;
        }
        st.erase(val);
    }
    for (int i = 1; i <= right.size(); i++) st.insert(i);
    for (int i = 0; i < right.size(); i++) {
        auto it = st.upper_bound(right[i].second);
        int val;
        if (it == st.begin()) {
            val = *st.rbegin();
        } else {
            it--;
            val = *it;
            sum += right[i].first;
        }
        st.erase(val);
    }
    return sum;
}
int main() {
    int t;
    cin >> t;
    vector<ll> res;
    while (t--) res.push_back(solve());
    for (ll r : res) cout << r << endl;
}