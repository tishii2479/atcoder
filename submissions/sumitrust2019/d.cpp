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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < 1000; i++) {
        int a = i / 100;
        int b = (i / 10) % 10;
        int c = i % 10;
        bool fa = false;
        bool fb = false;
        bool fc = false;
        for (int j = 0; j < s.length(); j++) {
            if (fa == false) {
                if (s[j] - '0' == a)
                    fa = true;
            } else if (fb == false) {
                if (s[j] - '0' == b)
                    fb = true;
            } else if (fc == false) {
                if (s[j] - '0' == c) {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
}