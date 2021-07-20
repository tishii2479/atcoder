#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, x, y;
    cin >> n >> a >> x >> y;
    int b = max(n - a, 0);
    cout << min(a, n) * x + b * y << endl;
}
