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
int k;
void f(vector<int> a, int l, int next) {
    a.push_back(next);
    if (a.size() == l) {
        k--;
        if (k == 0) {
            rep(i, a.size()) {
                cout << a[i];
            }
            cout << endl;
        }
        return;
    }
    if (next - 1 >= 0)
        f(a, l, next - 1);
    f(a, l, next);
    if (next + 1 < 10)
        f(a, l, next + 1);
}
int main() {
    cin >> k;
    vector<int> a;
    int l = 1;
    while (k > 0) {
        for (int i = 1; i < 10; i++) {
            f(a, l, i);
        }
        l++;
    }
}