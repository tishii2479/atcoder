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
const ll INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int flip = 0;
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            flip++;
            continue;
        }
        int f;
        char c;
        cin >> f >> c;
        if (f == 1) {
            if (flip % 2 == 0) {
                s = c + s;
            } else {
                s += c;
            }
        } else {
            if (flip % 2 == 0) {
                s += c;
            } else {
                s = c + s;
            }
        }
    }
    if (flip % 2 == 1) {
        reverse(s.begin(), s.end());
    }
    cout << s << endl;
}