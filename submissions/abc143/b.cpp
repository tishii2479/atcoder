#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> delicious;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        delicious.push_back(d);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += delicious[i] * delicious[j];
        }
    }
    cout << sum << endl;
}