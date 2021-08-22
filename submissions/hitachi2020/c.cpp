#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> d;

void dfs(int v = 0, int par = -1) {
    for (int u : edges[v]) {
        if (u == par) continue;
        d[u] = d[v] + 1;
        dfs(u, v);
    }
}

int main() {
    int n;
    cin >> n;

    d.resize(n), edges.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> cnt(4);
    for (int i = 1; i <= 3; i++) cnt[i] = n / 3;
    if (n % 3 == 1) cnt[1]++;
    if (n % 3 == 2) cnt[1]++, cnt[2]++;

    d[0] = 0;
    dfs();

    int cur[4] = {0, 1, 2, 3};
    vector<int> d_cnt(4, 0);

    for (int i = 0; i < n; i++) {
        d_cnt[d[i] % 2 + 1]++;
    }

    vector<int> res(n);
    if (d_cnt[1] < cnt[1]) {
        // 1 <- 3
        // 2 <- 1, 2, 3
        for (int i = 0; i < n; i++) {
            int val = d[i] % 2 + 1;
            if (val == 1) {
                res[i] = cur[3];
                cur[3] += 3;
            } else {
                for (int j = 1; j <= 3; j++) {
                    if (cur[j] <= n) {
                        res[i] = cur[j];
                        cur[j] += 3;
                        break;
                    }
                }
            }
        }
    } else if (d_cnt[2] < cnt[2]) {
        // 2 <- 3
        // 1 <- 1, 2, 3
        for (int i = 0; i < n; i++) {
            int val = d[i] % 2 + 1;
            if (val == 2) {
                res[i] = cur[3];
                cur[3] += 3;
            } else {
                for (int j = 1; j <= 3; j++) {
                    if (cur[j] <= n) {
                        res[i] = cur[j];
                        cur[j] += 3;
                        break;
                    }
                }
            }
        }
    } else {
        // 2 <- 2, 3
        // 1 <- 1, 3
        for (int i = 0; i < n; i++) {
            int val = d[i] % 2 + 1;
            if (val == 1) {
                for (int j = 1; j <= 3; j += 2) {
                    if (cur[j] <= n) {
                        res[i] = cur[j];
                        cur[j] += 3;
                        break;
                    }
                }
            } else {
                for (int j = 2; j <= 3; j++) {
                    if (cur[j] <= n) {
                        res[i] = cur[j];
                        cur[j] += 3;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}
