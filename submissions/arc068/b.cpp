#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
        st.insert(a);
    }
    int twocnt = 0;
    for (pint m : mp) {
        int cnt = m.second;
        if (cnt > 1)
            if (cnt % 2 == 0) {
                twocnt++;
            }
    }
    if (twocnt % 2 == 0) {
        cout << st.size() << endl;
    } else {
        cout << st.size() - 1 << endl;
    }
}