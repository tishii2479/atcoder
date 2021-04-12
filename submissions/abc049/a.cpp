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
    string erase = "erase";
    string dream = "dream";
    string now;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'e') {
            now = erase;
        } else if (s[i] == 'd') {
            now = dream;
        } else {
            cout << "NO" << endl;
            return 0;
        }
        for (int j = 0; j < 5; j++) {
            if (i + j >= s.length()) {
                cout << "NO" << endl;
                return 0;
            }
            if (now[j] != s[i + j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
        // check erer
        i += 4;
        if (s[i + 1] == 'e' and s[i + 2] == 'r') {
            if (s[i + 3] == 'a')
                continue;
            if ((s[i + 3] == 'e' or s[i + 3] == 'd') == false and i + 3 != s.length()) {
                cout << "NO" << endl;
                return 0;
            } else
                i += 2;
        } else if (s[i + 1] == 'r') {
            if ((s[i + 2] == 'e' or s[i + 2] == 'd') == false and i + 2 != s.length()) {
                cout << "NO" << endl;
                return 0;
            } else
                i += 1;
        }
    }
    cout << "YES" << endl;
}