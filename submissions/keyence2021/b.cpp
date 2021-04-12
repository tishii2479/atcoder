#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int ans = 0;
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            now = min(k, cnt[i]);
        } else {
            now = min({k, now, cnt[i]});
        }
        ans += now;
    }
    cout << ans << endl;
}