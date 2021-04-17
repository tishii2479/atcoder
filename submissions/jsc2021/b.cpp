#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(1100, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        cnt[b]++;
    }
    for (int i = 0; i < 1100; i++) {
        if (cnt[i] == 1) cout << i << " ";
    }
    cout << endl;
}