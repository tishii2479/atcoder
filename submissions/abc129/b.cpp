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
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    int ans = inf;
    for (int t = 0; t <= 100; t++) {
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < n; i++) {
            if (i <= t)
                s1 += w[i];
            else
                s2 += w[i];
        }
        ans = min(ans, abs(s1 - s2));
    }
    cout << ans << endl;
}