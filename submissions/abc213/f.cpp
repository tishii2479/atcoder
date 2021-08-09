#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using S = long long;
S op(S a, S b) { return min(a, b); }
S e() { return 1LL << 60; }

int main() {
    int n;
    string s;
    cin >> n >> s;

    auto sa = atcoder::suffix_array(s);
    auto lcp = atcoder::lcp_array(s, sa);

    vector<long long> v(n, 0);
    for (int i = 0; i < n; i++) v[i] = n - i;

    using P = pair<long long, long long>;

    for (int _ = 0; _ < 2; _++) {
        stack<P> st;
        long long cur = 0;

        for (int i = 0; i + 1 < n; i++) {
            long long len = 1;
            while (st.size() and st.top().first >= lcp[i]) {
                len += st.top().second;
                cur -= st.top().first * st.top().second;
                st.pop();
            }

            cur += len * lcp[i];
            st.push({lcp[i], len});
            v[sa[i + 1]] += cur;
        }

        reverse(lcp.begin(), lcp.end());
        reverse(sa.begin(), sa.end());
    }

    for (int i = 0; i < n; i++) cout << v[i] << endl;
}
