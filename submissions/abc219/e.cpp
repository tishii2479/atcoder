#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

int main() {
    const int N = 4;
    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> a[i][j];

    int ans = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    for (int bit = 1; bit < (1 << (N * N)); bit++) {
        bool ok = true;
        // includes
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                int idx = i * N + j;
                if (!(bit & (1 << idx)) and a[i][j]) {
                    ok = false;
                }
            }

        atcoder::dsu uf(N * N);
        int need = __builtin_popcount(bit);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int d = 0; d < 4; d++) {
                    int ny = i + dy[d], nx = j + dx[d];
                    if (nx < 0 or ny < 0 or nx >= N or ny >= N) continue;
                    int idx = i * N + j, idx2 = ny * N + nx;
                    if (bit & (1 << idx) and bit & (1 << idx2)) uf.merge(idx, idx2);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int idx = i * N + j;
                if (bit & (1 << idx))
                    if (uf.size(idx) != need) ok = false;
            }
        }

        // connectivity
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                int idx = i * N + j;
                if (bit & (1 << idx)) continue;
                bool ok2 = false;
                vector<vector<bool>> seen(N, vector<bool>(N, false));

                stack<pair<int, int>> q;
                q.push({i, j});
                seen[i][j] = true;
                while (!q.empty() and ok2 == false) {
                    auto [y, x] = q.top();
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int ny = y + dy[d], nx = x + dx[d];
                        if (seen[ny][nx]) continue;
                        if (bit & (1 << (ny * N + nx))) continue;
                        if (ny == 0 or nx == 0 or ny == N - 1 or nx == N - 1) {
                            ok2 = true;
                            break;
                        }
                        seen[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
                if (!ok2) ok = false;
            }
        }
        ans += ok;
    }
    cout << ans << endl;
}
