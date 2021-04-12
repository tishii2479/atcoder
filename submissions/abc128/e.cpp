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
    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, int>> event;
    for (int i = 0; i < n; i++) {
        int s, t, x;
        cin >> s >> t >> x;
        event.push_back({s - x, 1, x});
        event.push_back({t - x, -1, x});
    }
    vector<int> res;
    sort(event.begin(), event.end());
    int id = 0;
    set<int> st;
    for (int i = 0; i < q; i++) {
        int d;
        cin >> d;
        for (; id < event.size() and get<0>(event[id]) <= d; id++) {
            if (get<1>(event[id]) == 1)
                st.insert(get<2>(event[id]));
            else
                st.erase(get<2>(event[id]));
        }
        if (st.empty())
            res.push_back(-1);
        else
            res.push_back(*st.begin());
    }
    for (int r : res)
        cout << r << endl;
}