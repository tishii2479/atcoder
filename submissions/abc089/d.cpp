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
    int h, w, d;
    cin >> h >> w >> d;
    int a[330][330];
    vector<pint> positions(100000);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int a;
            cin >> a;
            positions[a] = make_pair(i, j);
        }
    }
    vector<int> dist(100000, 0);
    for (int i = d + 1; i <= h * w; i++) {
        dist[i] = dist[i - d] + abs(positions[i].first - positions[i - d].first) + abs(positions[i].second - positions[i - d].second);
    }
    int q;
    cin >> q;
    int l, r;
    vector<int> res;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        int cost = dist[r] - dist[l];
        res.push_back(cost);
    }
    for (int i = 0; i < q; i++) {
        cout << res[i] << endl;
    }
}