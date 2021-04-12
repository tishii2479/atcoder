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
    int n, m;
    cin >> n >> m;
    vector<int> s(m);
    vector<char> c(m);
    rep(i, m) {
        cin >> s[i] >> c[i];
    }
    for (int i = 0; i < 1000; i++) {
        bool flag = false;
        string str = to_string(i);
        if (str.length() != n)
            continue;
        for (int j = 0; j < m; j++) {
            if (str[s[j] - 1] != c[j])
                flag = true;
        }
        if (flag)
            continue;
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;
}