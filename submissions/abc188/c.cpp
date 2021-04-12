#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    int n;
    cin >> n;
    vector<int> a((1 << n));
    for (int i = 0; i < (1 << n); i++)
        cin >> a[i];
    int left_mx = 0;
    int right_mx = 0;
    for (int i = 0; i < (1 << (n - 1)); i++)
        left_mx = max(left_mx, a[i]);
    for (int i = (1 << (n - 1)); i < (1 << n); i++)
        right_mx = max(right_mx, a[i]);
    if (left_mx < right_mx) {
        for (int i = 0; i < (1 << (n - 1)); i++)
            if (a[i] == left_mx)
                cout << i + 1 << endl;
    } else {
        for (int i = (1 << (n - 1)); i < (1 << n); i++)
            if (a[i] == right_mx)
                cout << i + 1 << endl;
    }
}