#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

const int N = 210000;

// bits, kind, is_smaller
mint dp[N][20][2];

int convert(char c) {
    if (0 <= c - '0' and c - '0' <= 9) return c - '0';
    return c - 'A' + 10;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();

    dp[0][0][0] = 1;

    set<int> st;

    for (int i = 0; i < n; i++) {
        int val = convert(s[i]);
        st.insert(val);
        int sz = st.size();

        dp[i + 1][sz][0] += 1;

        if (i > 0) {
            dp[i + 1][1][1] += 15;
        }

        int new_cnt = 0;
        for (int j = 0; j < val; j++)
            if (st.find(j) == st.end()) new_cnt++;

        for (int j = 0; j <= 16; j++) {
            if (j == 0)
                dp[i + 1][j + 1][1] += dp[i][j][0] * max(0, new_cnt - 1);
            else
                dp[i + 1][j + 1][1] += dp[i][j][0] * new_cnt;
            dp[i + 1][j][1] += dp[i][j][0] * max(0, val - new_cnt);
            dp[i + 1][j + 1][1] += dp[i][j][1] * (16 - j);
            dp[i + 1][j][1] += dp[i][j][1] * j;
        }
    }

    cout << (dp[n][k][0] + dp[n][k][1]).val() << endl;
}
