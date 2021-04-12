#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    set<int> st;
    int p;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> p;
        if (st.size() == 0 or p < *st.begin()) {
            cnt++;
        }
        st.insert(p);
    }
    cout << cnt << endl;
}