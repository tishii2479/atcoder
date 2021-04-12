#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 1; i < 10; i++) {
        if (n % i == 0) {
            int a = n / i;
            if (a < 10) {
                flag = true;
                break;
            }
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}