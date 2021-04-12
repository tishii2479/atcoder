#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    long long n;
    vector<long long> x;
    long long ans1 = 0, ans2 = 0, ans3 = -1;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long a, abs_a;
        cin >> a;
        abs_a = abs(a);
        ans1 += abs_a;
        ans2 += abs_a * abs_a;
        ans3 = max(ans3, abs_a);
    }
    double dans2 = sqrt((double)ans2);
    cout << ans1 << endl;
    printf("%.16lf\n", dans2);
    cout << ans3 << endl;
}