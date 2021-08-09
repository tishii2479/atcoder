#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    map<int, vector<int>> mpx, mpy;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mpx[b].push_back(i);
        mpy[a].push_back(i);
    }

    vector<pair<int, int>> res(n);
    int i = 1;
    for (auto m : mpx) {
        for (auto idx : m.second) res[idx].second = i;
        i++;
    }
    i = 1;
    for (auto m : mpy) {
        for (auto idx : m.second) res[idx].first = i;
        i++;
    }

    for (int i = 0; i < n; i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
}
