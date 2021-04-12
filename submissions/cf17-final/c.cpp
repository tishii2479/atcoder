#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    const int limit = 13;
    vector<int> cnt(limit, 0);
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        cnt[d]++;
    }
    for (int i = 0; i < limit; i++) {
        if (cnt[i] > 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    if (cnt[0] > 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << limit); bit++) {
        vector<bool> exist(25, false);
        exist[0] = exist[24] = true;
        for (int j = 0; j < limit; j++) {
            if (cnt[j] == 0)
                continue;
            if (cnt[j] == 2)
                exist[j] = exist[24 - j] = true;
            else if (cnt[j] == 1) {
                if (bit & (1 << j))
                    exist[j] = true;
                else
                    exist[24 - j] = true;
            }
        }
        int prev = 0;
        int mn = inf;
        for (int i = 1; i <= 24; i++) {
            if (exist[i]) {
                mn = min(i - prev, mn);
                prev = i;
            }
        }
        ans = max(mn, ans);
    }
    cout << ans << endl;
}