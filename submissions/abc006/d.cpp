#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int n;
vector<int> c;
int lis() {
    vector<int> dp(n, inf);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), c[i]);
        *it = c[i];
    }
    return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}
int main() {
    cin >> n;
    c.resize(n);
    for (int i = 0; i < n; i++)
        cin >> c[i], c[i]--;
    cout << n - lis() << endl;
}