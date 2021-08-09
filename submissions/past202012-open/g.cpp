#include <bits/stdc++.h>
using namespace std;

const int N = 4;
char s[N][N];
using P = pair<int, int>;  // y, x

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int need, vector<P> path, set<P> st) {
    if (need == path.size()) {
        cout << need << endl;
        for (auto p : path) cout << p.first + 1 << " " << p.second + 1 << endl;
        exit(0);
    }

    P cur = path[path.size() - 1];

    for (int d = 0; d < 4; d++) {
        int ny = dy[d] + cur.first, nx = dx[d] + cur.second;
        if (ny < 0 or nx < 0 or ny >= N or nx >= N) continue;
        if (s[ny][nx] == '.') continue;
        if (st.find({ny, nx}) != st.end()) continue;
        auto next_path = path;
        auto next_st = st;
        next_path.push_back({ny, nx});
        next_st.insert({ny, nx});
        dfs(need, next_path, next_st);
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) s[i][j] = '.';
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> s[i][j];

    int k = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            if (s[i][j] == '#') k++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s[i][j] != '#') continue;
            dfs(k, {{i, j}}, {{i, j}});
        }
    }
}
