#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    vector<pint> ab(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ab[i] = {a, b};
    }
    int k;
    cin >> k;
    int ans = 0;
    vector<pint> cd(k);
    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        cd[i] = {c, d};
    }
    for (int bits = 0; bits < (1 << k); bits++) {
        vector<int> on(n, 0);
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (bits & (1 << i)) {
                on[cd[i].first]++;
            } else {
                on[cd[i].second]++;
            }
        }
        for (int i = 0; i < m; i++) {
            if (on[ab[i].first] > 0 and on[ab[i].second] > 0)
                cnt++;
        }
        ans = max(cnt, ans);
    }
    cout << ans << endl;
}