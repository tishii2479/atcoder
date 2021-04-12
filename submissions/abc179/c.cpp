#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
int solve(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                count += 1;
            } else {
                count += 2;
            }
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    long long count = 0;
    for (int i = 1; i < n; i++) {
        count += solve(i);
    }
    cout << count << endl;
}