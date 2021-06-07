#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] += i;
    }

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[b[i]].push_back(i);
    }

    vector<int> s(n);
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        if (mp[a[i]].size() == cnt[a[i]]) {
            cout << -1 << endl;
            return 0;
        }
        s[i] = mp[a[i]][cnt[a[i]]++];
    }

    long long ans = 0;

    fenwick_tree<int> tree(n);

    for (int i = 0; i < n; i++) {
        ans += i - tree.sum(0, s[i]);
        tree.add(s[i], 1);
    }

    cout << ans << endl;
}
