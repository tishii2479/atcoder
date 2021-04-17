#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int i = 0;
    while (1) {
        if (i * x >= y * z) {
            cout << i - 1 << endl;
            return 0;
        }
        i++;
    }
}