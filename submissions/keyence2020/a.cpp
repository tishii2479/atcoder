#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> P;
int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int big = max(h, w);
    cout << ceil(1.0 * n / big) << endl;
}