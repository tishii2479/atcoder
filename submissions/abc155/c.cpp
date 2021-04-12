#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define each(i, mp) for (auto &i : mp)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define MOD 1000000007
// #define MOD 998244353
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const ll INF = 1LL << 60;
const int inf = 1 << 29;
void StringSort(vector<string> &S) {
    map<int, int> SwapInd;
    int maxi = 0;  //Sに含まれる文字列の最大文字列長
    for (int i = 0; i < S.size(); i++) {
        if (S[i].size() > maxi)
            maxi = S[i].size();
    }
    for (int i = 0; i < maxi; i++) {  //ここが右端の文字から左の文字へのループ
        //やりたいこと:Sの要素で、右からi+1文字目でソートするものを右側に,しないものを左側に持ってくる
        int k = maxi - i;  //今考えている文字が左から何文字目かを表す(indexではないので注意)
        int sort_num = 0;  //文字列長がk以上ある要素の個数
                           //ソートしたい文字列の個数と言い換えられる
        for (int j = 0; j < S.size(); j++) {
            if (S[j].size() >= k) {  //S[j]にk文字目が存在すればSwapInd[j]に記録
                SwapInd[j] = 1;
                sort_num++;  //インクリメント
            }
        }
        int swapped = 0;  //Sの右側グループの左端indexを0としたきのindex
        //ここからグループ分けをします
        for (int j = 0; j < S.size(); j++) {
            //ここで、S.size() - sort_num は右側と左側の境界である
            if (SwapInd[j] == 1 && j < S.size() - sort_num) {
                //j番目の文字列がソート対象（文字列長k以上）
                //かつ、S[j]が右側グループに入っていない
                if (SwapInd[S.size() - sort_num + swapped] == 0) {
                    //右側グループの左からswapped番目の文字列がソート対象でない場合
                    iter_swap(S.begin() + j, S.begin() + S.size() - sort_num + swapped);
                    //入れ替える
                } else {
                    //右側グループの左からswapped番目の文字列がソート対象である場合
                    //右側グループの左からswapped番目の文字列がソート対象でなくなるまで
                    //swappedをインクリメントする
                    while (SwapInd[S.size() - sort_num + swapped] != 0) {
                        swapped++;
                        if (S.size() - sort_num + swapped >= S.size()) {
                            break;  //out of index
                        }
                        if (S.size() - sort_num + swapped < S.size()) {
                            iter_swap(S.begin() + j, S.begin() + S.size() - sort_num + swapped);
                        }
                    }
                }
                SwapInd[j] = 0;                              //更新
                SwapInd[S.size() - sort_num + swapped] = 0;  //更新
                swapped++;                                   //左右境界から何番目に要素を追加するかを表す
            }                                                //Sのグループ分け完了
        }
        vector<string> WhatSorted(sort_num);
        vector<pair<int, int>> char_and_index(sort_num);
        //sortする文字とそのindex,
        for (int j = 0; j < sort_num; j++) {
            //(int)charの値は大文字小文字で異なるので、char_and_indexでは仮想的に全て統一する
            //S や WhatSorted内では大文字小文字を統一しないで良い
            if (S[S.size() - sort_num + j][k - 1] >= 65 && S[S.size() - sort_num + j][k - 1] <= 90) {
                char_and_index[j].first = (int)S[S.size() - sort_num + j][k - 1] + 32;
            } else {
                char_and_index[j].first = (int)S[S.size() - sort_num + j][k - 1];
            }
            char_and_index[j].second = j;
            WhatSorted[j] = S[S.size() - sort_num + j];  //境界からj番目の文字列
        }
        //マージソートなので同じ値同士の順番は保持
        stable_sort(char_and_index.begin(), char_and_index.end());
        for (int j = 0; j < sort_num; j++) {
            S[S.size() - sort_num + j] = WhatSorted[char_and_index[j].second];
            //WhatSortedの中身はk+1文字目以降で既にソートしてあるので、
            //k番目の文字が同じ場合の順番を保持しつつ、
            //k番目の文字ででソートすればk文字目以降でソートされた状態になる
            //つまり、char_and_indexにk文字目を入れ、それを文字が同じ場合の順番を保持しつつソートし、
            //char_and_indexでソートされた順番でWhatSortedから取り出せば良い
        }
    }
}
int main() {
    int n;
    cin >> n;
    map<string, int> dic;
    string s;
    rep(i, n) {
        cin >> s;
        dic[s]++;
    }
    vector<string> ss;
    int max = -1;
    each(d, dic) {
        if (d.second > max) {
            max = d.second;
            ss.clear();
            ss.push_back(d.first);
        } else if (d.second == max) {
            ss.push_back(d.first);
        }
    }
    StringSort(ss);
    rep(i, ss.size()) {
        cout << ss[i] << endl;
    }
}