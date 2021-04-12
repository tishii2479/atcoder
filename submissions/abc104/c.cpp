#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    ll d, g;
    cin >> d >> g;
    vector<pll> pc(d);
    for (int i = 0; i < d; i++) {
        int p, c;
        cin >> p >> c;
        pc[i] = {p, c};
    }
    int ans = inf;
    for (int bits = 0; bits < 1 << d; bits++) {
        ll sum = 0;
        int cnt = 0;
        set<int> complete;
        for (int i = 0; i < d; i++) {
            if (bits & (1 << i)) {
                complete.insert(i);
                cnt += pc[i].first;
                sum += pc[i].second + (i + 1) * 100 * pc[i].first;
            }
        }
        for (int i = d - 1; i >= 0 and sum < g; i--) {
            if (complete.find(i) != complete.end())
                continue;
            int p = pc[i].first;
            int c = pc[i].second;
            if (sum + (i + 1) * 100 * (p - 1) >= g) {
                int pp = (g - sum + (i + 1) * 100 - 1) / ((i + 1) * 100);
                sum += pp * (i + 1) * 100;
                cnt += pp;
                break;
            }
            sum += (i + 1) * 100 * (p - 1);
            cnt += p - 1;
        }
        // cout << sum << " " << cnt << endl;
        if (sum >= g)
            ans = min(cnt, ans);
    }
    cout << ans << endl;
}