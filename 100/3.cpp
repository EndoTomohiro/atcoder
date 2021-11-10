#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vl = vector<ll>;
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
    string s;
    cin >> s;

    int l = 0;
    rep(i, s.size()) rep2(j, i, s.size()) {
        bool ok = true;
        rep2(k, i, j+1) {
            if(s[k] != 'A' && s[k] != 'C' && s[k] != 'G' && s[k] != 'T') {
                ok = false;
                break;
            }
        }
        int x = j - i + 1;
        if (ok) chmax(l, x);
    }

    cout << l << endl;
}