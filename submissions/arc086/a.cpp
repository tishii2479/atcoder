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
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    vector<int> sa;
    for (auto m : mp) {
        sa.push_back(m.second);
    }
    sort(sa.begin(), sa.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < sa.size(); i++) {
        if (i < k)
            continue;
        ans += sa[i];
    }
    cout << ans << endl;
}