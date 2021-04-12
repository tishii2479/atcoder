#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int main() {
    using mint = modint1000000007;
    int n;
    string s;
    cin >> n >> s;
    int cur = 0;
    mint ans = 1;
    for (int i = 0; i < n * 2; i++) {
        if ((cur % 2 == 0 and s[i] == 'B') or
            (cur % 2 == 1 and s[i] == 'W'))
            cur++;
        else {
            ans *= cur;
            cur--;
        }
    }
    if (cur > 0)
        ans = 0;
    for (int i = 1; i <= n; i++)
        ans *= i;
    cout << ans.val() << endl;
}