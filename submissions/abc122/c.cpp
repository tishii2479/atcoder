#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i < n; i++) {
        cnt[i] = cnt[i - 1];
        if (s[i - 1] == 'A' and s[i] == 'C') {
            cnt[i]++;
        }
    }
    // for (int i = 0; i <= n; i++) cout << i << " " << cnt[i] << endl;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << cnt[r] - cnt[l] << endl;
    }
}