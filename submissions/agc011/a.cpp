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
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    sort(t.begin(), t.end());
    int ans = 0;
    int r = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt++;
        if (t[i] > r or cnt == c) {
            ans++;
            r = t[i] + k;
            cnt = 0;
        }
    }
    cout << ans << endl;
}