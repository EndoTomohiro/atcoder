#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
using msl = multiset<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 998244353;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll h, w;
    cin >> h >> w;
    vs c(h);
    rep(i, h) cin >> c[i];

    ll n = min(h, w);
    vl ans(n);

    rep(i, h) rep(j, w) {
        if (i > 0 && i < h - 1 && j > 0 && j < w - 1) {
            if (c[i][j] == '#' && c[i+1][j+1] == '#' && c[i+1][j-1] == '#' && c[i-1][j+1] == '#' && c[i-1][j-1] == '#') {
                ll cnt = 1;
                while (true) {
                    if (i - cnt > 0 && i + cnt < h - 1 && j - cnt > 0 && j < w - 1) {
                        if (c[i+cnt+1][j+cnt+1] == '#' && c[i+cnt+1][j-cnt-1] == '#' && c[i-cnt-1][j+cnt+1] == '#' && c[i-cnt-1][j-cnt-1] == '#') {
                            cnt++;
                        }
                        else break;
                    }
                    else break;
                }
                ans[cnt-1]++;
            }
        }
    }

    rep(i, n) cout << ans[i] << ' ';
    cout << endl;
}
