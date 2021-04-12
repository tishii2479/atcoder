#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
Int fn(Int n) {
    return (1 + n) * n / 2;
}
int main() {
    int n;
    cin >> n;
    Int sum = 0;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        sum += fn(b) - fn(a - 1);
    }
    cout << sum << endl;
}