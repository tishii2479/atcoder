#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
// #define MOD 1000000007
#define MOD 998244353
const Int INF = 1LL << 60;
const int inf = 1 << 29;
int main() {
    int n;
    string s;
    cin >> n >> s;
    list<char> L;
    rep(i, n)
        L.push_back(s[i]);
    int count = 0;
    bool foundFlag = true;
    while (foundFlag) {
        if (L.size() < 3)
            break;
        foundFlag = false;
        list<char>::iterator prev2 = L.end();
        list<char>::iterator prev1 = L.end();
        for (auto it = L.begin(); it != L.end(); it++) {
            if (prev2 != L.end() and prev1 != L.end()) {
                if (*prev2 == 'f' and *prev1 == 'o' and *it == 'x') {
                    count++;
                    auto temp2 = prev2;
                    auto temp1 = prev1;
                    if (prev2 != L.begin()) {
                        prev2--;
                    }
                    if (prev2 != L.begin()) {
                        prev2--;
                    }
                    if (prev1 != L.begin()) {
                        prev1--;
                    }
                    if (prev1 != L.begin()) {
                        prev1--;
                    }
                    L.erase(temp2);
                    L.erase(temp1);
                    L.erase(it);
                    foundFlag = true;
                    continue;
                }
            }
            prev2 = prev1;
            prev1 = it;
        }
    }
    cout << n - count * 3 << endl;
}