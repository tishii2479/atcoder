#include <bits/stdc++.h>
using namespace std;

void solve() {
    const int N = 1000;
    int n;
    cin >> n;
    vector<int> p(N);
    vector<int> pos(N);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        pos[p[i]] = i;
    }

    vector<int> res;

    if (n == 2) {
        if (p[0] != 0) res.push_back(0);
        cout << res.size() << endl;
        for (int r : res) cout << r + 1 << " ";
        cout << endl;
        return;
    }

    int cnt = 0;
    for (int i = 0; i < n - 3; i++) {
        int i_pos = pos[i];
        if (i_pos == i) continue;

        if (i_pos % 2 == cnt % 2) {
            // do somewhere
            int idx = n - 2;
            if (idx % 2 != cnt % 2) {
                idx--;
            }

            bool flag = false;
            if (p[idx] == i) flag = true;

            res.push_back(idx);
            swap(p[idx], p[idx + 1]);
            swap(pos[p[idx]], pos[p[idx + 1]]);

            cnt++;

            if (flag) {
                res.push_back(idx - 1);
                swap(p[idx - 1], p[idx]);
                swap(pos[p[idx - 1]], pos[p[idx]]);

                res.push_back(idx);
                swap(p[idx], p[idx + 1]);
                swap(pos[p[idx]], pos[p[idx + 1]]);

                cnt += 2;
            }
        }

        while (pos[i] != i) {
            res.push_back(pos[i] - 1);
            int prev_i = p[pos[i] - 1];
            swap(p[pos[i]], p[pos[i] - 1]);

            pos[i] = pos[i] - 1;
            pos[prev_i] = pos[i] + 1;

            cnt++;
        }
    }

    while (p[n - 3] != n - 3 or p[n - 2] != n - 2 or p[n - 1] != n - 1) {
        int idx = n - 3;
        if (cnt % 2 == 0 ^ (n - 3) % 2 == 0) {
            idx++;
        }
        cnt++;
        res.push_back(idx);
        swap(p[idx], p[idx + 1]);
    }

    cout << res.size() << endl;
    for (int r : res) cout << r + 1 << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
