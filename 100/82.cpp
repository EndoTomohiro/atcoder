#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
const long long INF = 1000000000000000;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, s, n) for (long long i = (long long)(s); i < (long long)(n); i++)
#define rep3(i, s, n) for (long long i = (long long)(n); i >= (long long)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    int n;
    cin >> n;

    vector<int> vec(0);

    while (n != 0) {
        int table[24][60][60];
        rep(i, 24) rep(j, 60) rep(k, 60) table[i][j][k] = 0;

        rep(i, n) {
            string start, goal;
            cin >> start >> goal;

            int sh = (start[0] - '0') * 10 + (start[1] - '0');
            int sm = (start[3] - '0') * 10 + (start[4] - '0');
            int ss = (start[6] - '0') * 10 + (start[7] - '0');
            int gh = (goal[0] - '0') * 10 + (goal[1] - '0');
            int gm = (goal[3] - '0') * 10 + (goal[4] - '0');
            int gs = (goal[6] - '0') * 10 + (goal[7] - '0');

            table[sh][sm][ss]++;
            table[gh][gm][gs]--;
        }

        rep(i, 24) rep(j, 60) rep(k, 60) {
            if (i == 0 && j == 0 && k == 0) continue;
            else if (j == 0 && k == 0) table[i][j][k] += table[i-1][59][59];
            else if (k == 0) table[i][j][k] += table[i][j-1][59];
            else table[i][j][k] += table[i][j][k-1];
        }

        int ans = 0;
        rep(i, 24) rep(j, 60) rep(k, 60) chmax(ans, table[i][j][k]);

        vec.push_back(ans);

        cin >> n;
    }

    rep(i, vec.size()) cout << vec[i] << endl;
}