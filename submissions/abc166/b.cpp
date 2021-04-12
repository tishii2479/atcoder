#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    bool flag[1000] = {};
    int count = 0;
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int c;
            cin >> c;
            if (flag[c] == false) {
                flag[c] = true;
                count++;
            }
        }
    }
    cout << n - count << endl;
}