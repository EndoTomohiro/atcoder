#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
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

    vector< pair<int, int> > a(n), b(n);
    rep(i, n) {
        cin >> a[i].first >> b[i].first;
        a[i].second = i;
        b[i].second = i;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a[0].second != b[0].second) cout << max(a[0].first, b[0].first) << endl;

    else {
        int x00 = a[0].first + b[0].first, x01 = max(a[0].first, b[1].first), x10 = max(a[1].first, b[0].first);
        cout << min(x00, min(x01, x10)) << endl;
    }
}