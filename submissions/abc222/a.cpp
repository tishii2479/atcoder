#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 4 - s.length(); i++) cout << "0";
    cout << s << endl;
}
