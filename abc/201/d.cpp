#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vs = vector<string>;
#define pi 3.14159265359;
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

int h, w;
vs a(2005);

int masu(int i, int j, bool tf) {
    if (tf) {
        if (a[i][j] == '+') return 1;
        else return -1;
    }
    else {
        if (a[i][j] == '+') return -1;
        else return 1;
    }
}

int point(int i, int j, bool tf) {
    if (i == 0 && j == 0) return 0;
    else if (i == 0) return point(i, j-1, !tf) + masu(i, j, tf);
    else if (j == 0) return point(i-1, j, !tf) + masu(i, j, tf);
    else if (tf) {
        return max(point(i, j-1, !tf), point(i-1, j, !tf)) + masu(i, j, tf);
    }
    else return min(point(i, j-1, !tf), point(i-1, j, !tf)) + masu(i, j, tf);
    /*
    if (i == h && j == w) return x;
    else if (i == h) j++;
    else if (j == w) i++;
    else if (tf) {
        if (point(i+1, j, !tf, x + masu(i+1, j, tf)) > point(i, j+1, !tf, x + masu(i, j+1, tf))) {
                i++;
            }
        else j++;
    }
    else {
        if (point(i+1, j, !tf, x + masu(i+1, j, tf)) < point(i, j+1, !tf, x + masu(i, j+1, tf))) {
                i++;
            }
        else j++;
    }
    return point(i, j, !tf, x + masu(i, j, tf));
    */
}

int main() {
    cin >> h >> w;
    rep(i, h) {
        cin >> a[i];
    }

    h--; w--;

    bool tf = ((h + w) % 2 == 0); 

    ll ans = point(h, w, tf);
    if (ans > 0) puts("Takahashi");
    else if (ans < 0) puts("Aoki");
    else puts("Draw");
}