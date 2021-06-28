#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long r = 0;
    for (int i = 0; i <= 1e7; i++) {
        if (a <= r * d) {
            cout << i << endl;
            return 0;
        }
        a += b;
        r += c;
    }

    cout << -1 << endl;
}
