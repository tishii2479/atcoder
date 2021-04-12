#include <iostream>
using namespace std;
int main() {
    int h, n;
    cin >> h >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        h -= a;
    }
    cout << ((h <= 0) ? "Yes" : "No") << endl;
}