#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
ll solve() {
    if (n == 2 or m == 2)
        return 0;
    if (n == 1 and m == 1)
        return 1;
    if (n == 1)
        return m - 2;
    if (m == 1)
        return n - 2;
    return (n - 2) * (m - 2);
}
int main() {
    cin >> n >> m;
    cout << solve() << endl;
}