#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000009
using namespace std;
typedef long long ll;
int main() {
    string s, t;
    cin >> s >> t;
    int ans = t.size(), count;
    for (int i = 0; i <= s.length() - t.length(); i++) {
        count = 0;
        for (int j = 0; j < t.length(); j++) {
            if (s[i + j] != t[j])
                count++;
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
}