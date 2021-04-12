#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
// #define MOD 998244353
const ll INF = 1LL << 60;
const int inf = 1 << 29;
int n;
ll T[10][10];
ll k;
int solve(vector<int> nums) {
    int prev = 0;
    int sum = 0;
    rep(i, nums.size()) {
        sum += T[prev][nums[i]];
        prev = nums[i];
    }
    sum += T[prev][0];
    if (k == sum) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    cin >> n >> k;
    rep(i, n) {
        rep(j, n) {
            cin >> T[i][j];
        }
    }
    vector<int> nums;
    for (int i = 1; i < n; i++)
        nums.push_back(i);
    int count = 0;
    do {
        count += solve(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    cout << count << endl;
    return 0;
}