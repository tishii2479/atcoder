#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int x, y;
    cin >> x >> y;
    if (x > y)
        swap(x, y);
    if (y - x < 3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}