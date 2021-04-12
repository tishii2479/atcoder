#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<long long> ret;
void divisor(long long n) {
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());  // 昇順に並べる
}
int main() {
    long long n;
    cin >> n;
    divisor(n);
    for (long long i = 0; i < ret.size(); i++) {
        cout << ret[i] << endl;
    }
}