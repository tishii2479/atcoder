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
    int n, k;
    cin >> n >> k;
    set<int> set;
    for (int i = 0; i < 10; i++)
        set.insert(i);
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        set.erase(a);
    }
    vector<int> d(set.begin(), set.end());
    for (int i = n; i <= 1000000; i++) {
        bool flag = true;
        int k = i;
        while (k > 0) {
            bool f = false;
            for (int j = 0; j < d.size(); j++) {
                if (k % 10 == d[j]) {
                    f = true;
                }
            }
            if (f == false) {
                flag = false;
                break;
            }
            k /= 10;
        }
        if (flag) {
            cout << i << endl;
            return 0;
        }
    }
}