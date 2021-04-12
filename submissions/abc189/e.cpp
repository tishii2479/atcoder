#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
struct S {
    ll x;
    ll y;
    ll r;
    S rev() {
        S s;
        s.x = -x;
        s.y = -y;
        s.r = -r;
        return s;
    }
};
#define ps pair<S, S>
int main() {
    int n;
    cin >> n;
    vector<pll> xy(n);
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        xy[i] = {x, y};
    }
    int m;
    cin >> m;
    // first = x, second = y
    vector<ps> op(m + 1);
    op[0].first = {1, 0, 0};
    op[0].second = {0, 1, 0};
    for (int i = 0; i < m; i++) {
        int c, p;
        cin >> c;
        if (c == 1) {
            op[i + 1].first = op[i].second;
            op[i + 1].second = op[i].first.rev();
        } else if (c == 2) {
            op[i + 1].first = op[i].second.rev();
            op[i + 1].second = op[i].first;
        } else {
            cin >> p;
            if (c == 3) {
                op[i + 1].first = op[i].first.rev();
                op[i + 1].first.r += 2 * p;
                op[i + 1].second = op[i].second;
            } else {
                op[i + 1].first = op[i].first;
                op[i + 1].second = op[i].second.rev();
                op[i + 1].second.r += 2 * p;
            }
        }
        // cout << op[i + 1].first.x << " " << op[i + 1].first.y << " " << op[i + 1].first.r << endl;
        // cout << op[i + 1].second.x << " " << op[i + 1].second.y << " " << op[i + 1].second.r << endl;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        b--;
        cout << op[a].first.x * xy[b].first + op[a].first.y * xy[b].second + op[a].first.r << " ";
        cout << op[a].second.x * xy[b].first + op[a].second.y * xy[b].second + op[a].second.r << endl;
    }
}