#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long res = 1;
    bool flag = true;
    bool zeroflag = false;
    long long aaa = pow(10, 18);
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (a > aaa / res) {
            flag = false;
        }
        if (a == 0) zeroflag = true;
        if (flag) {
            res *= a;
            if (res > aaa || res < 0) {
                flag = false;
                res = 1;
            }
        }
    }
    if (zeroflag)
        cout << 0 << endl;
    else if (flag)
        cout << res << endl;
    else
        cout << "-1" << endl;
}