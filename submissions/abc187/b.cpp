#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<pint> xy(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        xy[i] = {x, y};
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = abs(xy[i].first - xy[j].first);
            int dy = abs(xy[i].second - xy[j].second);
            if ((double)dy / dx <= 1.0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}