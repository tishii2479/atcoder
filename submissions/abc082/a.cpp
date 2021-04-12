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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for (auto m : mp) {
        if (m.second > m.first)
            ans += m.second - m.first;
        else if (m.second < m.first)
            ans += m.second;
    }
    cout << ans << endl;
}