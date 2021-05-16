#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];

    for (int i = 0; i < 3; i++) {
        if (a[i] * 2 == a[(i + 1) % 3] + a[(i + 2) % 3]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
