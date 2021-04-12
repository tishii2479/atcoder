#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    s2.erase(--s2.end());
    if (s2 == s1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}