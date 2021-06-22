#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
    const int N = 210000;
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    dsu uf(N);

    for (int i = 0; i < n / 2; i++) {
        uf.merge(a[i], a[n - i - 1]);
    }

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (uf.leader(i) == i) {
            ans += uf.size(i) - 1;
        }
    }

    cout << ans << endl;
}
