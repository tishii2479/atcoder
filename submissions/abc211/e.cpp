#include <bits/stdc++.h>
using namespace std;

int n, k;
int ans = 0;
vector<string> s;
set<vector<string>> st;

void dfs(int cnt = 1) {
    if (st.find(s) != st.end()) return;
    st.insert(s);

    // cout << cnt << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) cout << s[i][j] << " ";
    //     cout << endl;
    // }

    if (cnt == k) {
        ans++;
        return;
    }

    vector<pair<int, int>> nxt;
    pair<int, int> unit[4] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != '.') continue;

            bool ok = false;

            for (int d = 0; d < 4; d++) {
                int ni = unit[d].first + i, nj = unit[d].second + j;
                if (ni < 0 or nj < 0 or ni >= n or nj >= n) continue;
                if (s[ni][nj] == '@') ok = true;
            }

            if (ok) {
                nxt.push_back({j, i});
            }
        }
    }

    for (auto p : nxt) {
        int x = p.first, y = p.second;
        s[y][x] = '@';
        dfs(cnt + 1);
        s[y][x] = '.';
    }
}

int main() {
    cin >> n >> k;
    s.resize(n);

    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '#') continue;

            s[i][j] = '@';
            dfs();
            s[i][j] = '.';
        }
    }

    cout << ans << endl;
}
