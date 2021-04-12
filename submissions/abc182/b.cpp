#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007
// #define MOD 998244353
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    int a[1100];
    int ans = -1;
    int count = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= 1000; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] % i == 0)
                count++;
        }
        if (ans <= count) {
            ans = count;
            x = i;
        }
    }
    cout << x << endl;
}