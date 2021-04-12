#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MOD 1000000009
int main() {
    string s;
    cin >> s;
    int l = s.size();
    for (int i = 0; i < l; i++) {
        char c = s[i];
        if (c == '?') {
            if (i > 0) {
                if (s[i - 1] == 'P') {
                    cout << 'D';
                    continue;
                }
            }
            if (i != l - 1) {
                if (s[i + 1] == '?') {
                    cout << "PD";
                    i++;
                } else {
                    cout << 'D';
                }
            } else {
                cout << 'D';
            }
        } else {
            cout << c;
        }
    }
    cout << endl;
}