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
    int k, n;
    cin >> k >> n;
    int mind = -100;
    int first;
    int prev;
    cin >> prev;
    first = prev;
    int a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        mind = max(a - prev, mind);
        prev = a;
    }
    mind = max(mind, first + k - a);
    print(k - mind);
}