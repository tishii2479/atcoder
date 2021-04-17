#include <bits/stdc++.h>
using namespace std;
int main() {
    const int N = 210000;
    int a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (a % i == 0) {
            if (b / i - a / i >= 1) res = max(res, i);
        } else {
            if (b / i - a / i >= 2) res = max(res, i);
        }
    }
    cout << res << endl;
}