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
    int a = 0;
    int b = 0;
    rep(i, 3) {
        if (s[i] == 'A')
            a++;
        else
            b++;
    }
    if (a > 0 and b > 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}