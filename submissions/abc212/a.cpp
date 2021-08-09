#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (0 < a and b == 0) {
        cout << "Gold" << endl;
    } else if (a == 0 and 0 < b) {
        cout << "Silver" << endl;
    } else {
        cout << "Alloy" << endl;
    }
}
