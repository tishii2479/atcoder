#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long Int;
bool solve(int a, int b, int c) {
    vector<int> vec{a, b, c};
    do {
        if ((vec[0] * 100 + vec[1] * 10 + vec[2]) % 8 == 0)
            return true;
    } while (next_permutation(vec.begin(), vec.end()));
    return false;
}
int main() {
    string s;
    cin >> s;
    vector<int> nums;
    vector<int> counts;
    int n = s.length();
    for (int i = 0; i <= 9; i++) {
        counts.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        counts[s[i] - '0']++;
    }
    for (int i = 1; i <= 9; i++) {
        if (counts[i] > 3)
            counts[i] = 3;
        for (int j = 0; j < counts[i]; j++) {
            nums.push_back(i);
        }
    }
    n = nums.size();
    if (n == 1) {
        if (nums[0] == 8) {
            cout << "Yes" << endl;
            return 0;
        }
    } else if (n == 2) {
        if ((nums[0] * 10 + nums[1]) % 8 == 0 || (nums[1] * 10 + nums[0]) % 8 == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (solve(nums[i], nums[j], nums[k])) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}