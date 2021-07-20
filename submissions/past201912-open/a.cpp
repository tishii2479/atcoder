#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool isNum = true;

    for (int i = 0; i < s.length(); i++) {
        int val = s[i] - '0';
        if (val < 0 or val > 9) isNum = false;
    }

    if (isNum)
        cout << stoi(s) * 2 << endl;
    else
        cout << "error" << endl;
}
