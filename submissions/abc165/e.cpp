#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    if (m % 2 == 0) {
        a = m - 1;
        b = m;
    } else {
        a = m;
        b = m - 1;
    }
    for (int i = 1; i <= a + 1; i++) {
        if (i > a - i + 1)
            break;
        cout << i << " " << a - i + 2 << endl;
    }
    for (int i = 1; i <= b; i++) {
        if (n + i - b - 1 >= n - i + 1)
            break;
        cout << n + i - b - 1 << " " << n - i + 1 << endl;
    }
}