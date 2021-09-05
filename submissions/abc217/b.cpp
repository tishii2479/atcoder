#include <bits/stdc++.h>
using namespace std;

int main() {
    string s[4] = {
        "ABC",
        "ARC",
        "AGC",
        "AHC"};
    string str[3];
    for (int i = 0; i < 3; i++) cin >> str[i];

    for (int i = 0; i < 4; i++) {
        bool found = false;
        string t = s[i];
        for (int j = 0; j < 3; j++) {
            if (t == str[j]) found = true;
        }
        if (found == false) {
            cout << t << endl;
        }
    }
}
