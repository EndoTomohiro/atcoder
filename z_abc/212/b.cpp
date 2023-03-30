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
    string x;
    cin >> x;

    if (x[0] == x[1] && x[1] == x[2] && x[2] == x[3]) cout << "Weak" << endl;

    else {
        int x0 = x[0] - '0';
        int x1 = x[1] - '0';
        int x2 = x[2] - '0';
        int x3 = x[3] - '0';
        if ((x0 + 1) % 10 == x1 && (x1 + 1) % 10 == x2 && (x2 + 1) % 10 == x3) {
            cout << "Weak" << endl;
        }
        else cout << "Strong" << endl;
    }
}