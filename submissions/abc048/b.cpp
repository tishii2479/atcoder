#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == s[n - 1]) {
        if (n % 2 == 0)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    } else {
        if (n % 2 == 1)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
}