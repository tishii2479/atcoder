#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if (a[2] % 2 == a[0] % 2 and a[1] % 2 == a[2] % 2) {
        cout << (a[2] * 2 - a[1] - a[0]) / 2 << endl;
    } else {
        if (a[1] % 2 == a[0] % 2) {
            cout << (a[2] * 2 - a[1] - a[0] - 2) / 2 + 1 << endl;
        } else if (a[1] % 2 == a[2] % 2) {
            cout << (a[2] * 2 + 2 - a[1] - 1 - a[0]) / 2 + 1 << endl;
        } else {
            cout << (a[2] * 2 + 2 - a[1] - 1 - a[0]) / 2 + 1 << endl;
        }
    }
}