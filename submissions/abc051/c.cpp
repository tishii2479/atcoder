#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
void print(char c, int n) {
    for (int i = 0; i < n; i++)
        cout << c;
}
int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    print('U', ty - sy);
    print('R', tx - sx);
    print('D', ty - sy);
    print('L', tx - sx + 1);
    print('U', ty - sy + 1);
    print('R', tx - sx + 1);
    print('D', 1);
    print('R', 1);
    print('D', ty - sy + 1);
    print('L', tx - sx + 1);
    print('U', 1);
    cout << endl;
}