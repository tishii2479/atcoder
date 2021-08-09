#include <bits/stdc++.h>
using namespace std;

bool is_num(char c) {
    int val = c - '0';
    return (0 <= val and val < 10);
}

int main() {
    string s;
    long long x;
    cin >> s >> x;
    long long cur_length = 0;
    for (int i = 0; i < s.length(); i++) {
        if (is_num(s[i])) {
            int val = s[i] - '0';
            cur_length *= (val + 1);
        } else {
            cur_length++;
        }

        if (cur_length >= x) {
            // find
            x--;
            for (; i >= 0; i--) {
                if (is_num(s[i])) {
                    int val = s[i] - '0';
                    val += 1;
                    assert((cur_length % val) == 0);
                    cur_length = cur_length / val;
                    x = x % cur_length;
                } else {
                    if ((x % cur_length) == cur_length - 1) {
                        cout << s[i] << endl;
                        return 0;
                    }
                    cur_length--;
                }
            }
        }
    }
}
