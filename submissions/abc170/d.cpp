#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (Int i = 0; i < n; i++)
#define repd(i, n) for (Int i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
int b[1000001]{};
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    rep(i, n) {
        cin >> a[i];
        b[a[i]]++;
        s.insert(a[i]);
    }
    bool flag[1000001]{};
    for (int i : s) {
        for (int j = 2; j < 1000001; j++) {
            if (i * j >= 1000001)
                break;
            flag[i * j] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (b[a[i]] == 1 and flag[a[i]] == false)
            ans++;
    }
    cout << ans << endl;
}