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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> dist(10, vector<int>(10, 0));
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> dist[i][j];
    vector<vector<int>> field(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> field[i][j];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (field[i][j] == -1)
                continue;
            ans += dist[field[i][j]][1];
        }
    cout << ans << endl;
}