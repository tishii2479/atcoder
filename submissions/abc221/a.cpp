#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c = a - b;
    long long ans = 1;
    for (int i = 0; i < c; i++) ans *= 32;
    cout << ans << endl;
}
