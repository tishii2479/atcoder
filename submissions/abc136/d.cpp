#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const ll INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    string s;
    cin >> s;
    s += 'R';
    int sum = 0;
    int l = 0;
    int lbr;
    int rbr;
    vector<int> res(s.length(), 0);
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == 'L' and s[i] == 'R') {
            // result
            int sum = i - l + 1;
            for (int j = l; j < i; j++) {
                if (j % 2 == lbr % 2) {
                    res[lbr]++;
                } else {
                    res[rbr]++;
                }
            }
            // update
            l = i;
        }
        if (s[i - 1] == 'R' and s[i] == 'L') {
            lbr = i - 1;
            rbr = i;
        }
    }
    for (int i = 0; i < s.length() - 1; i++) {
        cout << res[i];
        if (i < s.length() - 1)
            cout << " ";
    }
    cout << endl;
}