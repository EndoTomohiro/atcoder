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
    ll n, k;
    cin >> n >> k;

    vector< vector<ll> > t(n, vector<ll> (n));
    rep(i, n)rep(j, n) cin >> t[i][j];

    vector<ll> num(n);
    rep(i, n) num[i] = i;

    int c = 0;

    sort(num.begin(), num.end());
    do {
        ll d = 0; 
        rep(i, n-1) d += t[num[i]][num[i+1]];
        d += t[num[n-1]][0];
        if (d == k) c++;
    } while (next_permutation(num.begin()+1, num.end()));

    cout << c << endl;
}