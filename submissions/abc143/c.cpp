#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    char now_c;
    int count = 1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (i == 0) {
            now_c = c;
        } else {
            if (now_c == c) {
                continue;
            } else {
                count++;
                now_c = c;
            }
        }
    }
    cout << count << endl;
}