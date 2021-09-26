#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        a[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++) cin >> a[i][j];
    }

    int p, q;
    cin >> p >> q;
    set<int> b;
    for (int i = 0; i < p; i++) {
        int v;
        cin >> v;
        b.insert(v);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < k[i]; j++) {
            if (b.find(a[i][j]) != b.end()) cnt++;
        }
        if (cnt >= q) ans++;
    }
    cout << ans << endl;
}
