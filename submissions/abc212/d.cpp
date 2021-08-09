#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int q;
    cin >> q;

    using P = pair<ll, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> sums(q + 1, 0);

    ll cur = 0;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            pq.push({x - cur, i});
        } else if (t == 2) {
            ll x;
            cin >> x;
            cur += x;
        } else {
            auto [mn, idx] = pq.top();
            pq.pop();
            cout << mn + cur << endl;
        }

        // sums[i] = cur;
    }
}
