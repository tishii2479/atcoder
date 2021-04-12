#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<int> zAlgo(string s) {
    vector<int> a(s.length(), 0);
    int left = -1, right = -1;
    for (int i = 1; i < s.length(); i++) {
        int &same = a[i];
        if (left != -1) {
            same = min(a[i - left], right - i);
            same = max(0, same);
        }
        while (same + i < s.length() and s[i + same] == s[same])
            same++;
        if (i + same > right) {
            right = i + same;
            left = i;
        }
    }
    a[0] = s.length();
    return a;
}
int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int k = 0; k < n; k++) {
        vector<int> a = zAlgo(s.substr(k, n));
        for (int j = 0; j < n - k; j++) {
            int w = min({j, a[j]});
            ans = max(ans, w);
        }
    }
    cout << ans << endl;
}