#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> P;
int main() {
    int x;
    cin >> x;
    for (int i = 2; i <= 100003; i++) {
        bool flag = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            P.push_back(i);
        }
    }
    int pSize = P.size();
    for (int i = 0; i < pSize; i++) {
        if (P[i] >= x) {
            cout << P[i] << endl;
            break;
        }
    }
}