#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1ll << 60;
const int inf = 1 << 29;
ll powint(int x, int n) {
    ll res = 1;
    rep(i, n) {
        res *= x;
    }
    return res;
}
int main() {
    ll n;
    cin >> n;
    vector<int> name;
    int m = 0;
    while (powint(26, m) <= n) {
        n -= powint(26, m);
        m++;
    }
    string s = "";
    rep(i, m) {
        s = (char)('a' + n % 26) + s;
        n /= 26;
    }
    cout << s << endl;
}