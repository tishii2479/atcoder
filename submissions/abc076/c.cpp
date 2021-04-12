#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
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
    string s, t;
    cin >> s >> t;
    int first = -1;
    for (int i = 0; i + t.length() - 1 < s.length(); i++) {
        for (int j = 0; j < t.length(); j++) {
            if (!(s[i + j] == '?' or s[i + j] == t[j])) {
                break;
            }
            if (j == t.length() - 1) {
                first = i;
            }
        }
    }
    if (first == -1) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); i++) {
        if (i == first) {
            for (int j = 0; j < t.length(); j++) {
                cout << t[j];
            }
            i += t.length() - 1;
        } else if (s[i] == '?')
            cout << 'a';
        else
            cout << s[i];
    }
    cout << endl;
}