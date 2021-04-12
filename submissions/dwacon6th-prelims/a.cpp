#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> v;
    for (int i = 0; i < n; i++) {
        string s;
        int t;
        cin >> s >> t;
        v.push_back({s, t});
    }
    string x;
    cin >> x;
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        string s = v[i].first;
        int t = v[i].second;
        if (s == x) {
            flag = true;
            continue;
        }
        if (flag) {
            ans += t;
        }
    }
    cout << ans << endl;
}