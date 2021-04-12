#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int MAX = 1100000;
vector<int> edges[MAX];
vector<int> h(MAX, 0);
vector<int> depth(MAX, -1);
vector<int> ans;
int N;
void input() {
    int n;
    cin >> n;
    N = n * (n - 1) / 2;
    vector<vector<int>> id(n, vector<int>(n, -1));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            id[i][j] = cnt;
            id[j][i] = cnt;
            cnt++;
        }
    }
    for (int i = 0; i < n; i++) {
        int last;
        for (int j = 0; j < n - 1; j++) {
            int a;
            cin >> a;
            a--;
            if (j > 0) {
                edges[last].push_back(id[i][a]);
                h[id[i][a]]++;
            }
            last = id[i][a];
        }
    }
}
void bfs() {
    queue<int> que;
    for (int i = 0; i < N; i++) {
        if (h[i] == 0) {
            que.push(i);
            depth[i] = 0;
        }
    }
    while (que.empty() == false) {
        int v = que.front();
        que.pop();
        ans.push_back(v);
        for (int u : edges[v]) {
            depth[u] = max(depth[u], depth[v] + 1);
            h[u]--;
            if (h[u] == 0)
                que.push(u);
        }
    }
}
int main() {
    input();
    bfs();
    if (ans.size() == N) {
        cout << *max_element(depth.begin(), depth.end()) + 1 << endl;
    } else {
        cout << -1 << endl;
    }
}