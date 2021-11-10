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
const ll inf = 1000000000000000;
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
    string s;
    cin >> s;

    vl vec(8);
    rep(i, s.size()) {
        if (s[i] == 'c') {
            vec[0]++;
            vec[0] %= 1000000000 + 7;
        }
        else if (s[i] == 'h') {
            vec[1] += vec[0];
            vec[1] %= 1000000000 + 7;
        }
        else if (s[i] == 'o') {
            vec[2] += vec[1];
            vec[2] %= 1000000000 + 7;
        }
        else if (s[i] == 'k') {
            vec[3] += vec[2];
            vec[3] %= 1000000000 + 7;
        }
        else if (s[i] == 'u') {
            vec[4] += vec[3];
            vec[4] %= 1000000000 + 7;
        }
        else if (s[i] == 'd') {
            vec[5] += vec[4];
            vec[5] %= 1000000000 + 7;
        }
        else if (s[i] == 'a') {
            vec[6] += vec[5];
            vec[6] %= 1000000000 + 7;
        }
        else if (s[i] == 'i') {
            vec[7] += vec[6];
            vec[7] %= 1000000000 + 7;
        }
    }

    cout << vec[7] << endl;
}