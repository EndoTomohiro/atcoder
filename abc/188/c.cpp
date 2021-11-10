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

    vector< pair<ll, ll> > a(1 << n);
    rep(i, 1 << n) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    ll half = a.size() / 2;
    vector< pair<ll, ll> > x(half), y(half);

    rep(i, half) {
        x[i].first = a[i].first;
        x[i].second = a[i].second;
        y[i].first = a[i + half].first;
        y[i].second = a[i + half].second;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    if (x[half-1].first < y[half-1].first) cout << x[half-1].second << endl;
    else cout << y[half-1].second << endl;

}