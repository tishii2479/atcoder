#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k > a + b) {
        cout << a - (k - a - b) << endl;
    } else {
        cout << min(a, k) << endl;
    }
}