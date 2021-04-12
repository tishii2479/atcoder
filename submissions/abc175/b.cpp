#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<int> L(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        L[i] = a;
    }
    int l = n;
    int count = 0;
    sort(L.begin(), L.end());
    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l; j++) {
            for (int k = j + 1; k < l; k++) {
                if (L[i] + L[j] > L[k]) {
                    if (L[i] != L[j] && L[j] != L[k] && L[i] != L[k])
                        count++;
                }
            }
        }
    }
    cout << count << endl;
}