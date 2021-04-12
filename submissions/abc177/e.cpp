#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
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
    vector<ll> a(n);
    vector<ll> num(1001000, 0), isprime(1001000, true);
    rep(i, n) {
        cin >> a[i];
        num[a[i]]++;
    }
    bool flag = true;
    for (int j = 2; j < 1001000; j++) {
        if (isprime[j] == false)
            continue;
        ll sum = 0;
        for (int i = j; i < 1001000; i += j) {
            sum += num[i];
            isprime[i] = false;
        }
        if (sum > 1) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    ll g = 0;
    for (ll i = 0; i < n; i++)
        g = gcd(g, a[i]);
    if (g == 1) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }
}