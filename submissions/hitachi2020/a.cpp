#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
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
    if (s.length() % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == 0) {
            if (s[i] != 'h') {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (s[i] != 'i') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}