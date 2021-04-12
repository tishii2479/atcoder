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
int main() {
    string s;
    cin >> s;
    bool flag = true;
    int n = s.length();
    for (int i = 0; i < (n - 1) / 2; i++)
        if (s[i] != s[n - i - 1])
            flag = false;
    int j = (n - 1) / 2 - 1;
    for (int i = 0; i < n; i++) {
        if (i > j)
            break;
        if (s[i] != s[j])
            flag = false;
        j--;
    }
    j = n - 1;
    for (int i = (n + 3) / 2; i < n; i++) {
        if (i > j)
            break;
        if (s[i] != s[j])
            break;
        j--;
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}