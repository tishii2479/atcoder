#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
    using mint = modint1000000007;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<mint> fibo(n + 1);
    fibo[0] = 1, fibo[1] = 1;
    for (int i = 2; i <= n; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];

    mint ans = 0;

    for (int i = 0; i < n; i++) {
        ans += a[i] * fibo[i] * fibo[n - i];
        if (i - 1 >= 0 and n - i - 1 >= 0) ans -= a[i] * fibo[i - 1] * fibo[n - i - 1];
    }

    cout << ans.val() << endl;
}
