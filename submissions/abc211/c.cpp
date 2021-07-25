#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using mint = atcoder::modint1000000007;

int main() {
    string s;
    cin >> s;
    const int n = s.length();
    const string t = "chokudai";
    vector<mint> dp(t.length() + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t.length(); j++) {
            if (s[i] == t[j]) {
                dp[j + 1] += dp[j];
            }
        }
    }

    cout << dp[t.length()].val() << endl;
}
