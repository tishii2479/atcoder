#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<pair<int, int>, int> mp;
    map<int, vector<int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[x].push_back(y);
    }

    long long ans = 0;
    for (auto m : points) {
        auto v = m.second;
        const int N = v.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int y1 = v[i], y2 = v[j];
                if (y2 > y1) swap(y1, y2);
                // y1 < y2
                ans += mp[{y1, y2}];
                mp[{y1, y2}]++;
            }
        }
    }
    cout << ans << endl;
}
