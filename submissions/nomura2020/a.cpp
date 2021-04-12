#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MOD 1000000009
int main() {
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    cout << (h2 - h1) * 60 + (m2 - m1) - k << endl;
}