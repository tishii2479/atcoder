#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    if (s == "Y") {
        if (t == "a") {
            cout << "A" << endl;
        } else if (t == "b") {
            cout << "B" << endl;
        } else {
            cout << "C" << endl;
        }
    } else {
        cout << t << endl;
    }
}