#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

int main() {
    using mint = atcoder::modint1000000007;
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(c.begin(), c.end());

    mint res = 1;

    for (int i = 0; i < n; i++) {
        res *= max(0, c[i] - i);
    }

    cout << res.val() << endl;
}
