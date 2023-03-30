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
    ll n;
    cin >> n;

    vector<ll> vec(0);

    rep2(i, 2, 100001) {
        ll a = i * i;
        while (a <= n) {
            vec.push_back(a);
            a *= i;
        }
    }

    sort(vec.begin(), vec.end());

    ll c = 0;

    if (vec.size() > 0) {
        c++;
        rep(i, vec.size()-1) {
            if (vec[i] != vec[i+1]) c++;
        }
    }

    cout << n - c << endl;
}