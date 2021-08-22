#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

using mint = atcoder::modint1000000007;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    mint ma = mint(A), mb = mint(B), mc = mint(C);

    const int lim = (int)1e8;
    mint inv_c = mc.inv();

    for (int c = 1; c <= lim; c++) {
        mint r = c * mb * inv_c;
        if ((r + c - 1) * ma == c * mb) {
            cout << (r - 1).val() << " " << c - 1 << endl;
            return 0;
        }
    }
}
