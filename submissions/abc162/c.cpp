#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int gcd(int a, int b) {
    if (a % b == 0) {
        return (b);
    } else {
        return (gcd(b, a % b));
    }
}
int main() {
    int k;
    cin >> k;
    long long sum = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= k; l++) {
                sum += gcd(l, gcd(i, j));
            }
        }
    }
    cout << sum << endl;
}