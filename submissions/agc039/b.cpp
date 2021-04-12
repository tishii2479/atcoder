#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    string s[210];
    ll dist[210][210];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<int> color(n, 0);
    color[0] = 1;
    queue<int> q;
    q.push(0);
    while (q.empty() == false) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (i == v or s[v][i] == '0')
                continue;
            else if (color[i] == 0) {
                color[i] = -color[v];
                q.push(i);
            } else {
                if (color[i] == color[v]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (s[i][j] == '0')
                dist[i][j] = inf;
            else
                dist[i][j] = 1;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mx = max(mx, dist[i][j]);
        }
    }
    cout << mx + 1 << endl;
}