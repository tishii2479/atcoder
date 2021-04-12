#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
int solve() {
    using mint = modint1000000007;
    long long n, a, b;
    cin >> n >> a >> b;
    if (n < a + b) return 0;
    mint res = mint(n - b + 1) * (n - b + 1) * (n - a + 1) * (n - a + 1);
    mint x =
        mint(n - a + 1) * (n - b + 1) - mint(n - a - b + 2) * (n - a - b + 1);
    res -= x * x;
    return res.val();
}
int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
}