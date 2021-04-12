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
int scnt[110000];
int pcnt[110000];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int p;
        string s;
        cin >> p >> s;
        if (s == "WA") {
            if (scnt[p] == 0)
                pcnt[p]++;
        } else {
            scnt[p]++;
        }
    }
    int sans = 0;
    int pans = 0;
    for (int i = 0; i < 110000; i++) {
        if (scnt[i] > 0) {
            sans++;
            pans += pcnt[i];
        }
    }
    cout << sans << " " << pans << endl;
}