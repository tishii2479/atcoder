#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cnt(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cnt[a]++;
        cnt[b]++;
    }

    for (int i = 0; i < n; i++) {
        if (cnt[i] == n - 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
