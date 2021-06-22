#include <bits/stdc++.h>
using namespace std;

string solve(int a, int b, int c) {
    if (a == b) {
        return "=";
    }
    if (c % 2 == 0) {
        if (abs(a) == abs(b))
            return "=";
        else if (abs(a) > abs(b))
            return ">";
        return "<";
    } else {
        if (a > b)
            return ">";
        else
            return "<";
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << endl;
}
