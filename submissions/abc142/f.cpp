#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1100;
vector<int> edges[N];
vector<int> inv_edges[N];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        inv_edges[b].push_back(a);
    }
    int mn = 1 << 30;
    int mns = -1;
    for (int s = 0; s < n; s++) {
        vector<int> dist(n, (1e9));
        queue<int> que;
        for (int u : edges[s]) {
            que.push(u);
            dist[u] = 1;
        }
        while (que.empty() == false) {
            int v = que.front();
            que.pop();
            for (int u : edges[v]) {
                if (dist[u] > dist[v] + 1) {
                    dist[u] = dist[v] + 1;
                    que.push(u);
                }
            }
        }
        int now = s;
        vector<int> path;
        bool flag = false;
        do {
            for (int u : inv_edges[now]) {
                if (u == s) {
                    flag = true;
                    now = u;
                    break;
                }
                if (dist[u] == dist[now] - 1) {
                    now = u;
                    break;
                }
            }
            path.push_back(now);
        } while (now != s);
        if (flag) {
            if (path.size() < mn)
                mns = s, mn = path.size();
        }
    }
    if (mn == 1 << 30)
        cout << -1 << endl;
    else {
        int s = mns;
        vector<int> dist(n, (1e9));
        queue<int> que;
        for (int u : edges[s]) {
            que.push(u);
            dist[u] = 1;
        }
        while (que.empty() == false) {
            int v = que.front();
            que.pop();
            for (int u : edges[v]) {
                if (dist[u] > dist[v] + 1) {
                    dist[u] = dist[v] + 1;
                    que.push(u);
                }
            }
        }
        int now = s;
        vector<int> path;
        bool flag = false;
        do {
            for (int u : inv_edges[now]) {
                if (u == s) {
                    flag = true;
                    now = u;
                    break;
                }
                if (dist[u] == dist[now] - 1) {
                    now = u;
                    break;
                }
            }
            path.push_back(now);
        } while (now != s);
        cout << path.size() << endl;
        for (int p : path)
            cout << p + 1 << endl;
    }
}