#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    int l = s.size();
    int a[5];
    for (int i = 0; i < l; i++) {
        a[i] = s[i] - '0';
    }
    for (int bit = 0; bit < 1 << (l - 1); bit++) {
        int ans = a[0];
        for (int i = 1; i < l; i++) {
            if (bit & (1 << i - 1)) {
                ans += a[i];
            } else {
                ans -= a[i];
            }
        }
        if (ans == 7) {
            for (int i = 0; i < l; i++) {
                cout << a[i];
                if (i < l - 1) {
                    if (bit & (1 << i)) {
                        cout << "+";
                    } else {
                        cout << "-";
                    }
                }
            }
            cout << "=7" << endl;
            return 0;
        }
    }
    cout << "NOTFOUND" << endl;
}