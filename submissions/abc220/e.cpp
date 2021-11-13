#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

int main() {
    using mint = atcoder::modint998244353;
    int n, d;
    cin >> n >> d;

    mint ans = 0;

    for (int i = 0; i <= d; i++) {
        int left = i, right = d - i;
        if (n - max(left, right) < 0) continue;
        ans += (mint(2).pow(n - max(left, right)) - 1) * mint(2).pow(max(0, i - 1)) * mint(2).pow(max(0, d - i - 1));
    }

    cout << (ans * 2).val() << endl;
}
