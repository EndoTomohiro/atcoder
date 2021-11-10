#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vvl = vector<vl>;
using vvp = vector<vp>;
using vs = vector<string>;
const double pi = 3.14159265359;
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
    string a, b, c;
    cin >> a >> b >> c;

    if (a != "ABC" && b != "ABC" && c != "ABC") cout << "ABC" << endl;
    else if (a != "ARC" && b != "ARC" && c != "ARC") cout << "ARC" << endl;
    else if (a != "AGC" && b != "AGC" && c != "AGC") cout << "AGC" << endl;
    else cout << "AHC" << endl;
}