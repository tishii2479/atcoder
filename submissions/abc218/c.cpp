#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(n));
    vector<vector<char>> t(n, vector<char>(n));

    int s_cnt = 0, t_cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
            if (s[i][j] == '#') s_cnt++;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
            if (t[i][j] == '#') t_cnt++;
        }

    if (s_cnt != t_cnt) {
        cout << "No" << endl;
        return 0;
    }

    set<pair<int, int>> st_t;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (t[i][j] == '#') st_t.insert({i, j});

    for (int _ = 0; _ < 5; _++) {
        set<pair<int, int>> st_s;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (s[i][j] == '#') st_s.insert({i, j});

        auto p = *st_s.begin();
        for (auto tp : st_t) {
            bool ok = true;
            int dy = tp.first - p.first, dx = tp.second - p.second;
            for (auto sp : st_s) {
                int y = dy + sp.first, x = dx + sp.second;
                if (st_t.find({y, x}) == st_t.end()) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                // cout << dy << " " << dx << " " << _ << endl;
                // for (int i = 0; i < n; i++) {
                //     for (int j = 0; j < n; j++) cout << s[i][j];
                //     cout << endl;
                // }
                cout << "Yes" << endl;
                return 0;
            }
        }

        // rotate
        vector<vector<char>> tmp(n, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp[j][n - i - 1] = s[i][j];
            }
        }

        swap(s, tmp);
    }

    cout << "No" << endl;
}
