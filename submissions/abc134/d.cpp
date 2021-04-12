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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> b(n + 1, 0);
    int m = 0;
    for (int i = n; i >= 1; i--) {
        int cnt = 0;
        for (int j = 1; j * i <= n; j++) {
            cnt += b[j * i];
        }
        if (a[i] % 2 != cnt % 2) {
            b[i] = 1;
            m++;
        }
    }
    cout << m << endl;
    if (m == 0) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
}