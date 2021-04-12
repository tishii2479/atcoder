#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
vector<int> p(110000, -1);
vector<int> edges[110000];
vector<int> in(110000, 0);
void bfs(int r) {
    queue<int> q;
    q.push(r);
    while (q.empty() == false) {
        int v = q.front();
        q.pop();
        for (int u : edges[v]) {
            in[u]--;
            if (in[u] > 0)
                continue;
            p[u] = v;
            q.push(u);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1 + m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        in[b]++;
        edges[a].push_back(b);
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0)
            root = i;
    }
    bfs(root);
    for (int i = 0; i < n; i++)
        cout << p[i] + 1 << endl;
}