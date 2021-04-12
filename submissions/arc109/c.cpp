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
typedef long long Int;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (Int i = 0; i < n; i++)
#define repd(i, n) for (Int i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
char f(char a, char b) {
    if ((a == 'R' and b == 'S') or (a == 'S' and b == 'R') or (a == 'R' and b == 'R'))
        return 'R';
    else if ((a == 'P' and b == 'S') or (a == 'S' and b == 'P') or (a == 'S' and b == 'S'))
        return 'S';
    else
        return 'P';
}
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < k; i++) {
        string t = s + s;
        s = "";
        for (int k = 0; k < n; k++) {
            s += (f(t[2 * k], t[2 * k + 1]));
        }
    }
    cout << s[0] << endl;
}