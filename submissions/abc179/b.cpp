#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
int main() {
    int n, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            count++;
            if (count == 3) {
                cout << "Yes" << endl;
                return 0;
            }
        } else {
            count = 0;
        }
    }
    cout << "No" << endl;
}