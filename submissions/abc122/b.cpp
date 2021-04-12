#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s;
    cin >> s;
    char c[4] = {'A', 'C', 'G', 'T'};
    int n = s.length();
    int l = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < 4; j++) {
            if (s[i] == c[j])
                ok = true;
        }
        if (ok) {
            continue;
        } else {
            ans = max(i - l, ans);
            l = i + 1;
        }
    }
    ans = max(n - l, ans);
    cout << ans << endl;
}