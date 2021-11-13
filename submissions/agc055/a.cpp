#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> cnt(3, vector<int>(3, 0));
    for (int i = 0; i < 3 * n; i++) {
        cnt[i / n][s[i] - 'A']++;
    }

    vector<vector<int>> use(6, vector<int>(3, 0));
    int p[6][3] = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 1, 0},
        {2, 0, 1},
    };

    for (int i = 0; i < 6; i++) {
        int a = p[i][0], b = p[i][1], c = p[i][2];
        int mn = min({cnt[0][a], cnt[1][b], cnt[2][c]});

        cnt[0][a] -= mn;
        cnt[1][b] -= mn;
        cnt[2][c] -= mn;

        use[i][0] = use[i][1] = use[i][2] = mn;
    }

    string t = "";
    for (int i = 0; i < 3 * n; i++) {
        bool ok = false;
        for (int j = 0; j < 6; j++) {
            if (s[i] - 'A' == p[j][i / n] and use[j][i / n] > 0) {
                t += '1' + j;
                ok = true;
                use[j][i / n]--;

                break;
            }
        }

        assert(ok);
    }

    cout << t << endl;
}
