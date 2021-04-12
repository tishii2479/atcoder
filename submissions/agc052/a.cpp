#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < 3; i++)
        cin >> s;
    cout << string(n, '0') + string(n, '1') + '0' << endl;
}
int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}