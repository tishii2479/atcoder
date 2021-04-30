#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int m;
    cin >> m;
    ll csum = 0;
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        ll d, c;
        cin >> d >> c;
        csum += c;
        sum += d * c;
    }

    cout << csum - 1 + (sum - 1) / 9 << endl;
}
