#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cur = 1;
    while (n > 0) {
        n -= cur;
        cur++;
    }
    cout << cur - 1 << endl;
}
