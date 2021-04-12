#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (a < 10 && b < 10) {
        cout << a * b << endl;
    } else {
        cout << -1 << endl;
    }
}