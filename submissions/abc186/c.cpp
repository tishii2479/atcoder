#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
#define each(i, mp) for (auto &i : mp)
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
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        string s = to_string(i);
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '7') {
                flag = false;
                break;
            }
        }
        std::stringstream ss;
        ss << oct << i;
        string t = ss.str();
        for (int j = 0; j < t.length(); j++) {
            if (t[j] == '7') {
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
    }
    cout << cnt << endl;
}