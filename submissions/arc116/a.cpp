#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string solve() {
    ll n;
    cin >> n;
    if (n == 2)
        return "Same";
    if (n % 2 == 0) {
        n /= 2;
        if (n % 2 == 0)
            return "Even";
        else
            return "Same";
    } else
        return "Odd";
}
int main() {
    int t;
    cin >> t;
    while (t--)
        cout << solve() << endl;
}