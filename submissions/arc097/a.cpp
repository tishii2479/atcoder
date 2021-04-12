#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
const int MOD = 1000000007;
// const int MOD = 998244353;
int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    for (int j = 0; j < 26; j++) {
        vector<int> st;
        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a';
            if (a == j) {
                st.push_back(i);
            }
        }
        set<string> cand;
        for (int i = 0; i < st.size(); i++) {
            string a = "";
            for (int k = 0; k < 5 and st[i] + k < n; k++) {
                a += s[k + st[i]];
                cand.insert(a);
            }
        }
        int cnt = 1;
        for (string ca : cand) {
            if (cnt == k) {
                cout << ca << endl;
                return 0;
            }
            cnt++;
        }
        k -= cand.size();
    }
}