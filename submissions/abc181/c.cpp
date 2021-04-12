#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
int main() {
    int x, y;
    int n;
    cin >> n;
    vector<int> xs;
    vector<int> ys;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (xs[j] - xs[i] == 0 && xs[k] - xs[i] == 0) {
                    cout << "Yes" << endl;
                    return 0;
                }
                if (xs[j] != xs[i] &&
                    ys[k] * (xs[j] - xs[i]) == ys[i] * (xs[j] - xs[i]) + (ys[j] - ys[i]) * (xs[k] - xs[i])) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}