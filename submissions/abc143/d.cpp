#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n;
    vector<int> sticks;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        sticks.push_back(l);
    }
    sort(sticks.begin(), sticks.end());
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (sticks[j] * 2 < sticks[i]) break;
            for (int k = j - 1; k >= 0; k--) {
                if (sticks[k] + sticks[j] > sticks[i])
                    count++;
                else
                    break;
            }
        }
    }
    cout << count << endl;
}