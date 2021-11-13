#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

int main() {
    using mint = atcoder::modint998244353;
    string s;
    cin >> s;
    const int n = s.length();

    mint ans = 0;
    mint cur = 0;
    for (int i = 0; i < n; i++) {
        cur += mint(10).pow(i) * mint(2).pow(max(0, n - i - 2));
    }

    for (int i = 0; i < n; i++) {
        ans += cur * (s[i] - '0');

        if (i < n - 1) {
            cur -= mint(2).pow(i) * mint(10).pow(n - i - 1);
            cur += mint(2).pow(i) * mint(10).pow(n - i - 2);
        }
    }

    cout << ans.val() << endl;
}
