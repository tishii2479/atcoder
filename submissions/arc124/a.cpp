#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

using mint = atcoder::modint998244353;

int main() {
    int N, K;
    cin >> N >> K;
    vector<char> c(K);
    vector<int> k(K);

    for (int i = 0; i < K; i++) cin >> c[i] >> k[i];

    int cur = K;
    vector<int> lcnt(N), rcnt(N);
    for (int i = 0; i < K; i++) {
        int idx = k[i] - 1;
        if (c[i] == 'L') {
            lcnt[idx]++;
            cur--;
        } else {
            rcnt[idx]++;
        }
    }

    mint ans = 1;

    for (int i = 0; i < N; i++) {
        if (lcnt[i] + rcnt[i] > 1) cur = 0;
        if (lcnt[i] + rcnt[i] == 0) ans *= cur;
        cur += lcnt[i] - rcnt[i];
    }

    cout << ans.val() << endl;
}
