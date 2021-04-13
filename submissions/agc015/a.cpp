#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, a, b;
ll solve() {
    if (a > b) return 0;
    if (a != b and n == 1) return 0;
    return (b - a) * (n - 2) + 1;
}
int main() {
    cin >> n >> a >> b;
    cout << solve() << endl;
}