#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> cur(26, n);
    vector<vector<int>> nxt(n);
    for (int i = n - 1; i >= 0; i--) {
        int c = s[i] - 'a';
        cur[c] = i;
        nxt[i] = cur;
    }

    string ans = "";
    int now = 0;
    while (ans.length() < k) {
        for (int i = 0; i < 26; i++) {
            if (nxt[now][i] < n - (k - ans.length()) + 1) {
                ans += (char)('a' + i);
                now = nxt[now][i] + 1;
                break;
            }
        }
    }

    cout << ans << endl;
}
