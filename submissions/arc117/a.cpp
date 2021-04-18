#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int asum = 0, bsum = 0;
    if (a > b) {
        for (int i = 1; i <= a; i++) {
            cout << i << " ";
            asum += i;
        }
        for (int i = 1; i <= b - 1; i++) {
            cout << -i << " ";
            bsum += i;
        }
        cout << bsum - asum;
    } else {
        for (int i = 1; i <= a - 1; i++) {
            cout << i << " ";
            asum += i;
        }
        for (int i = 1; i <= b; i++) {
            cout << -i << " ";
            bsum += i;
        }
        cout << bsum - asum;
    }
    cout << endl;
}
