#include <bits/stdc++.h>
using namespace std;

int solve() {
    vector<int> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];

    int ans = 1 << 30;
    for (int i = 0; i < 3; i++) {
        vector<int> a;
        for (int j = 0; j < 3; j++)
            if (j != i) a.push_back(v[j]);

        if (a[0] > a[1]) swap(a[0], a[1]);
        // v[0] <= v[1]
        int diff = abs(a[0] - a[1]);
        if (diff % 3 != 0) continue;

        int time = diff / 3;
        int plus = a[1] - time;
        ans = min(ans, time + plus);
    }

    if (ans == 1 << 30) {
        return -1;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
