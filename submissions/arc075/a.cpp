#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    const int N = 11000;
    vector<bool> dp(N, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (j + s[i] < N) {
                if (dp[j]) {
                    dp[j + s[i]] = true;
                }
            }
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        if (dp[i] and i % 10 != 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}
