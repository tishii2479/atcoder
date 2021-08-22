#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    p.push_back(-1);

    int left = -1, ans = 0;
    for (int i = 0; i <= n; i++) {
        if (p[i] == i) {
            if (left == -1) left = i;
        } else {
            if (left == -1) continue;
            ans += (i - left + 1) / 2;
            left = -1;
        }
    }

    cout << ans << endl;
}
