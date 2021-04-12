#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<char> op(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == "AB") {
            if (a > b)
                a--, b++, op[i] = 'B';
            else if (a < b or i == n - 1)
                a++, b--, op[i] = 'A';
            else {
                if (s[i + 1] == "BC")
                    b++, a--, op[i] = 'B';
                else
                    b--, a++, op[i] = 'A';
            }
        } else if (s[i] == "BC") {
            if (b > c)
                b--, c++, op[i] = 'C';
            else if (b < c or i == n - 1)
                b++, c--, op[i] = 'B';
            else {
                if (s[i + 1] == "AB")
                    b++, c--, op[i] = 'B';
                else
                    b--, c++, op[i] = 'C';
            }
        } else if (s[i] == "AC") {
            if (a > c)
                a--, c++, op[i] = 'C';
            else if (a < c or i == n - 1)
                a++, c--, op[i] = 'A';
            else {
                if (s[i + 1] == "AB")
                    a++, c--, op[i] = 'A';
                else
                    a--, c++, op[i] = 'C';
            }
        }
        if (a < 0 or b < 0 or c < 0) {
            cout << "No" << endl;
            return 0;
        }
        // cout << a << " " << b << " " << c << endl;
    }
    cout << "Yes" << endl;
    for (char c : op)
        cout << c << endl;
}