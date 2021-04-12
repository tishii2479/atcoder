#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> heights;
    vector<vector<int>> paths(n);
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        heights.push_back(h);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        paths[a - 1].push_back(b - 1);
        paths[b - 1].push_back(a - 1);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        int l = paths[i].size();
        int height = heights[i];
        bool flag = true;
        for (int j = 0; j < l; j++) {
            if (height <= heights[paths[i][j]]) {
                flag = false;
                break;
            }
        }
        if (flag) count++;
    }
    cout << count << endl;
}