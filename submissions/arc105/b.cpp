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
void print(Int n) {
    printf("%lld\n", n);
}
void print(int n) {
    printf("%d\n", n);
}
void print(double d) {
    printf("%.12lf\n", d);
}
void print(string s) {
    printf("%s\n", s.c_str());
}
int main() {
    int n;
    cin >> n;
    vector<Int> a(n);
    rep(i, n) cin >> a[i];
    Int s = a[0];
    Int ans;
    for (int i = 0; i < n; i++) {
        ans = gcd(s, a[i]);
        s = ans;
    }
    print(ans);
}