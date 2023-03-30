#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
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

    vector< pair<int, int> > xy(n);
    rep(i, n) cin >> xy[i].first >> xy[i].second;

    rep(i, n-2)rep2(j, i+1, n-1)rep2(k, j+1, n) {
        auto [x1, y1] = xy[i];
        auto [x2, y2] = xy[j];
        auto [x3, y3] = xy[k];

        x1 -= x3;
        x2 -= x3;
        y1 -= y3;
        y2 -= y3;

        if (x1 * y2 == x2 * y1) {
            puts("Yes");
            return 0;
        }
    }

    puts("No");
}