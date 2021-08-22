#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int v;
    if (n <= 125) {
        v = 4;
    } else if (n <= 211) {
        v = 6;
    } else {
        v = 8;
    }
    cout << v << endl;
}
