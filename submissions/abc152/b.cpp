#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define pll pair<ll, ll>
const ll INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    // b > a
    for (int i = 0; i < b; i++)
        cout << a;
    cout << endl;
}