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
    int m;
    cin >> m;
    vector<int> x(m), y(m);
    for (int i = 0; i < m; i++)
        cin >> x[i] >> y[i];
    int n;
    cin >> n;
    vector<pint> xy(n);
    for (int i = 0; i < n; i++)
        cin >> xy[i].first >> xy[i].second;
    set<pint> st;
    for (int i = 0; i < n; i++)
        st.insert(xy[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int dx = xy[i].first - x[j];
            int dy = xy[i].second - y[j];
            bool flag = true;
            for (int k = 0; k < m and flag; k++) {
                int px = x[k], py = y[k];
                if (st.find({px + dx, py + dy}) != st.end())
                    continue;
                flag = false;
            }
            if (flag) {
                cout << dx << " " << dy << endl;
                return 0;
            }
        }
    }
}