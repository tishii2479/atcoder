#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<int> edges[110000];
int parent[110000];
vector<int> depth(110000, -1);
void dfs(int v) {
    for (int u : edges[v]) {
        if (depth[u] != -1)
            continue;
        parent[u] = v;
        depth[u] = depth[v] + 1;
        dfs(u);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    parent[0] = -1;
    depth[0] = 0;
    dfs(0);
    int bor = n - 1;
    int d = depth[n - 1];
    for (int i = 0; i < (d - 1) / 2; i++) {
        bor = parent[bor];
    }
    queue<int> q;
    q.push(0);
    int cnt = 0;
    while (q.empty() == false) {
        int v = q.front();
        q.pop();
        if (v == bor)
            continue;
        cnt++;
        for (int u : edges[v]) {
            if (u != parent[v]) {
                q.push(u);
            }
        }
    }
    if (cnt > n / 2) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
}