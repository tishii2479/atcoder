#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int y, int x) {
}

int main() {
    int h, w, r, c;
    cin >> h >> w >> r >> c;
    r--, c--;
    vector<string> s(h);
    vector<vector<bool>> ok(h, vector<bool>(w, false));
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) cin >> s[i];
    ok[r][c] = true;

    queue<pair<int, int>> q;
    q.push({r, c});
    char dir[4] = {'^', '<', 'v', '>'};
    while (q.size()) {
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = dy[d] + y, nx = dx[d] + x;
            if (nx < 0 or nx >= w or ny < 0 or ny >= h) continue;
            if (!(s[ny][nx] == '.' or s[ny][nx] == dir[d])) continue;
            if (s[ny][nx] == '#') continue;
            if (seen[ny][nx]) continue;
            ok[ny][nx] = true;
            seen[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (ok[i][j])
                cout << "o";
            else {
                if (s[i][j] == '#')
                    cout << '#';
                else
                    cout << "x";
            }
        }
        cout << endl;
    }
}
