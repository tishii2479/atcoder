#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int minCost = -1;
int n, m, x;
vector<vector<int>> books(15);
void solve(vector<int> book_flag) {
    vector<int> bookPoint(15);
    int cost = 0;
    for (int i = 0; i < n; i++) {
        if (book_flag[i] == 1) {
            cost += books[i][0];
            for (int j = 0; j < m; j++) {
                bookPoint[j] += books[i][j + 1];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (bookPoint[i] < x) {
            cost = -1;
            break;
        }
    }
    if ((cost != -1 && cost < minCost) || minCost == -1) {
        minCost = cost;
    }
}
void subBin(vector<int> book_flag, int n) {
    if (n == 0) {
        solve(book_flag);
    }
    if (n > 0) {
        vector<int> temp = book_flag;
        book_flag.push_back(0);
        subBin(book_flag, n - 1);
        temp.push_back(1);
        subBin(temp, n - 1);
    }
}
int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        books[i].push_back(c);
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            books[i].push_back(a);
        }
    }
    subBin({}, n);
    cout << minCost << endl;
}