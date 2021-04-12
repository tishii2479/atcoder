#include <bits/stdc++.h>
using namespace std;
vector<string> v, w;
int k, n;
void dfs(int cur, int cur_v, int cur_w, vector<string> s) {
    // cout << cur << " " << cur_v << " " << cur_w << endl;
    // for (int i = 1; i < s.size(); i++) cout << i << " " << s[i] << " ";
    // cout << endl;
    if (cur == n) {
        for (auto str : s)
            if (str != "") cout << str << endl;
        // for (auto str : s) cout << str << endl;
        exit(0);
    }
    int a = v[cur][cur_v] - '0';
    if (s[a] == "") {
        for (int i = 1; i <= 3; i++) {
            if (cur_w + i > w[cur].length()) return;
            string str = "";
            for (int j = 0; j < i; j++) {
                str += w[cur][cur_w + j];
            }
            int tmp_w, tmp_v, tmp;
            tmp_w = cur_w, tmp_v = cur_v, tmp = cur;
            tmp_w += i;
            tmp_v++;
            if (tmp_v == v[tmp].length()) {
                if (tmp_w != w[tmp].length()) continue;
                tmp_v = 0;
                tmp_w = 0;
                tmp++;
            }
            s[a] = str;
            dfs(tmp, tmp_v, tmp_w, s);
        }
    } else {
        for (int i = 0; i < s[a].length(); i++) {
            if (cur_w + i >= w[cur].length() or s[a][i] != w[cur][cur_w + i])
                return;
        }
        int tmp_w, tmp_v, tmp;
        tmp_w = cur_w, tmp_v = cur_v, tmp = cur;
        tmp_w += s[a].length();
        tmp_v++;
        if (tmp_v == v[tmp].length()) {
            if (tmp_w != w[tmp].length()) return;
            tmp_v = 0;
            tmp_w = 0;
            tmp++;
        }
        dfs(tmp, tmp_v, tmp_w, s);
    }
}
int main() {
    cin >> k >> n;
    v.resize(n), w.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
    vector<string> s(10, "");
    dfs(0, 0, 0, s);
}