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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int l = 0; l < n; l++) {
        int cur = a[l];
        for (int r = l; r < n; r++) {
            cur = min(cur, a[r]);
            ans = max(cur * (r - l + 1), ans);
        }
    }
    cout << ans << endl;
}