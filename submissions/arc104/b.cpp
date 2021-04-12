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
int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int c1 = 0;
        int c2 = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == 'A')
                c1++;
            if (s[j] == 'T')
                c1--;
            if (s[j] == 'C')
                c2++;
            if (s[j] == 'G')
                c2--;
            if (c1 == 0 and c2 == 0)
                ans++;
        }
    }
    cout << ans << endl;
}