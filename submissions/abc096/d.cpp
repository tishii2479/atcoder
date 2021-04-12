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
vector<bool> isPrime(60000, true);
int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i < 60000; i++) {
        if (isPrime[i] == false)
            continue;
        for (int j = 2; i * j < 60000; j++) {
            isPrime[i * j] = false;
        }
    }
    vector<int> ans;
    ans.push_back(2);
    for (int i = 3; i <= 55000; i++) {
        if (isPrime[i] and i % 5 == 2) {
            ans.push_back(i);
            if (ans.size() == n)
                break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}