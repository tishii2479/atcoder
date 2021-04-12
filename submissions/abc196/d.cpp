#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll h, w, a, b;
ll ans = 0;
void dfs(int cnt, vector<vector<bool>> used, vector<vector<bool>> used2) {
    if (cnt == a) {
        ans++;
        return;
    }
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w + 1; j++) {
            if (j == 0 or j == w)
                continue;
            if (used[i][j])
                continue;
            auto tmp = used;
            auto tmp2 = used2;
            used[i][j] = used[i][j - 1] = used[i][j + 1] = true;
            used2[i][j] = used2[i][j - 1] = used2[i + 1][j - 1] = used2[i + 1][j] = true;
            dfs(cnt + 1, used, used2);
            used = tmp;
            used2 = tmp2;
            used[i][j] = true;
        }
    for (int i = 0; i < h + 1; i++)
        for (int j = 0; j < w; j++) {
            if (i == 0 or i == h)
                continue;
            if (used2[i][j])
                continue;
            auto tmp = used;
            auto tmp2 = used2;
            used2[i][j] = used2[i - 1][j] = used2[i + 1][j] = true;
            used[i][j] = used[i - 1][j] = used[i][j + 1] = used[i - 1][j + 1] = true;
            dfs(cnt + 1, used, used2);
            used = tmp;
            used2 = tmp2;
            used2[i][j] = true;
        }
}
int main() {
    cin >> h >> w >> a >> b;
    // used := tate
    // used2 := yoko
    vector<vector<bool>> used(h + 1, vector<bool>(w + 1, false));
    vector<vector<bool>> used2(h + 1, vector<bool>(w + 1, false));
    dfs(0, used, used2);
    cout << ans << endl;
}