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
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    set<int> fast_st;
    for (int i = 0; i < n; i++)
        if (s[i] == 'o') {
            fast_st.insert(i);
            i += c;
        }
    reverse(s.begin(), s.end());
    set<int> slow_st;
    for (int i = 0; i < n; i++)
        if (s[i] == 'o') {
            slow_st.insert(n - i - 1);
            i += c;
        }
    // for (int s : fast_st)
    //     cout << s + 1 << " ";
    // cout << endl;
    // for (int s : slow_st)
    //     cout << s + 1 << " ";
    // cout << endl;
    if (fast_st.size() > k or slow_st.size() > k) {
        cout << endl;
        return 0;
    } else {
        for (int s : fast_st)
            if (slow_st.find(s) != slow_st.end())
                cout << s + 1 << endl;
    }
}