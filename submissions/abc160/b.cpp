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
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (Int i = 0; i < n; i++)
#define repd(i, n) for (Int i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
void print(int n) {
    cout << n << endl;
}
void print(string s) {
    cout << s << endl;
}
int main() {
    Int x;
    cin >> x;
    Int a, b;
    a = x / 500;
    x -= a * 500;
    b = x / 5;
    print(a * 1000 + b * 5);
}