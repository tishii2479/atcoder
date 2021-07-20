#include <bits/stdc++.h>
using namespace std;

int main() {
    using ll = long long;
    int n, k;
    ll p;
    cin >> n >> k >> p;
    vector<ll> former, latter;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (i % 2 == 0)
            former.push_back(a);
        else
            latter.push_back(a);
    }

    vector<ll> all_former[21], all_latter[21];
    int former_size = former.size();
    for (int bit = 0; bit < (1 << former_size); bit++) {
        ll sum = 0;
        for (int i = 0; i < former_size; i++) {
            if (bit & (1 << i)) sum += former[i];
        }
        int cnt = __builtin_popcount(bit);
        all_former[cnt].push_back(sum);
    }

    int latter_size = latter.size();
    for (int bit = 0; bit < (1 << latter_size); bit++) {
        ll sum = 0;
        for (int i = 0; i < latter_size; i++) {
            if (bit & (1 << i)) sum += latter[i];
        }
        int cnt = __builtin_popcount(bit);
        all_latter[cnt].push_back(sum);
    }

    for (int i = 0; i <= 20; i++) {
        sort(all_former[i].begin(), all_former[i].end());
        sort(all_latter[i].begin(), all_latter[i].end());
    }

    ll ans = 0;

    for (int i = 0; i <= min(20, k); i++) {
        for (ll val : all_former[i]) {
            int j = k - i;
            if (j > 20) continue;
            if (all_latter[j].size() == 0) continue;
            if (p - val < 0) continue;
            ll cnt = upper_bound(all_latter[j].begin(), all_latter[j].end(), p - val) - all_latter[j].begin();
            ans += cnt;
        }
    }

    cout << ans << endl;
}
