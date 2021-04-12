#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    long long a, b, k;
    cin >> a >> b >> k;
    if (a > k) {
        a -= k;
        k = 0;
    } else {
        k -= a;
        a = 0;
    }
    b -= k;
    b = max(0ll, b);
    cout << a << " " << b << endl;
}