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
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);
    for (int i = 0; i < A; i++)
        cin >> a[i];
    for (int i = 0; i < B; i++)
        cin >> b[i];
    int mina = *min_element(a.begin(), a.end());
    int minb = *min_element(b.begin(), b.end());
    int minp = mina + minb;
    for (int i = 0; i < M; i++) {
        int wa, wb, wc;
        cin >> wa >> wb >> wc;
        minp = min(minp, a[wa - 1] + b[wb - 1] - wc);
    }
    cout << minp << endl;
}