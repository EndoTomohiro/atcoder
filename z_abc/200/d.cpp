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

int main() {
    int n;
    cin >> n;

    vl a = vl(n);
    rep(i, n) cin >> a[i];

    auto bitmax = bitset<8>("11111111");
    vector< bitset<8> > abit = vector< bitset<8> >(200, bitmax);

    int cnt = min(n, 8);

    rep2(i, 1, 1 << cnt) {        
        bitset<8> bit(i);
        ll amari = 0;
        rep(j, 8) {
            if (bit.test(j)) {
                amari += a[j];
                amari %= 200;
            }
        }

        if (abit[amari] == bitmax) {
            abit[amari] = bit;
        }

        else {
            puts("Yes");

            cout << abit[amari].count();  
            rep(j, 8) {
                if (abit[amari].test(j)) cout << ' ' << j + 1;
            }
            cout << endl;

            cout << bit.count();
            rep(j, 8) {
                if (bit.test(j)) cout << ' ' << j + 1;
            }
            cout << endl;

            exit(0);
        }
    }

    puts("No");
}