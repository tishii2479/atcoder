#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<bool> ok(m + 1, true);
    set<int> fact;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                fact.insert(j);
                fact.insert(a[i] / j);
            }
        }
    }

    for (auto e : fact) {
        if (e == 1) continue;
        for (int i = 1; i * e <= m; i++) {
            ok[i * e] = false;
        }
    }

    vector<int> res;
    for (int i = 1; i <= m; i++)
        if (ok[i]) res.push_back(i);

    cout << res.size() << endl;
    for (int e : res) cout << e << endl;
}
