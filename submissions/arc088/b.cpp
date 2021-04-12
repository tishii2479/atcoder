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
    string s;
    cin >> s;
    int n = s.length();
    int ans = n;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            int k = max(i + 1, n - i - 1);
            ans = min(k, ans);
        }
    }
    cout << ans << endl;
}