#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
int main() {
    ll n, p;
    cin >> n >> p;
    mint res = mint(p - 1) * mint(p - 2).pow(n - 1);
    cout << res.val() << endl;
}