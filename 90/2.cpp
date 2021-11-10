#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
#define pi 3.14159265359;
const ll INF = 1000000000000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
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

    if (n % 2 != 0) exit(0);

    n /= 2;

    vvs kakko(n+1);
    kakko[1].push_back("()");

    rep2(v, 2, n+1) {
        rep(a, kakko[v-1].size()) {
            kakko[v].push_back('(' + kakko[v-1][a] + ')');
        }
        rep2(i, 1, v) {
            int j = v - i;
            rep(b, kakko[i].size()) rep(c, kakko[j].size()) {
                kakko[v].push_back(kakko[i][b] + kakko[j][c]);
            }
        }

        sort(all(kakko[v]));
        kakko[v].erase(unique(all(kakko[v])), kakko[v].end());
    }

    rep(i, kakko[n].size()) cout << kakko[n][i] << endl;
}