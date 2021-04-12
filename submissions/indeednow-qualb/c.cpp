#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 29;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<int> edges[110000];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;
    vector<bool> found(110000, false);
    pq.push(1);
    for (int i = 0; i < n; i++) {
        int next = pq.top();
        pq.pop();
        found[next] = true;
        res.push_back(next);
        for (int u : edges[next]) {
            if (found[u])
                continue;
            pq.push(u);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl;
}