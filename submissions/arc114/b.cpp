#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
int main() {
    int n;
    cin >> n;
    atcoder::dsu dsu(n + 1);
    for (int i = 1; i <= n; i++) {
        int f;
        cin >> f;
        dsu.merge(i, f);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (dsu.leader(i) == i)
            cnt++;
    cout << atcoder::pow_mod(2, cnt, 998244353) - 1 << endl;
}