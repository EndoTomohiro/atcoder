#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using ql = queue<ll>;
using ml = map<ll, ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll x;
    cin >> x;

    if (x < 10) cout << x << endl;

    else if (x < 100000) {
        while (true) {
            string s = to_string(x);
            ll d = s[1] - s[0];
            bool ok = true;
            rep2(i, s.size() - 2) {
                if (d != s[i + 1] - s[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << x << endl;
                return 0;
            }
            x++;
        }
    }

    else if (x < 1000000) {
        vl vec = {111111, 123456, 222222, 234567, 333333, 345678, 444444, 456789, 543210, 555555, 654321, 666666, 765432, 777777, 876543, 888888, 987654, 999999};
        rep(i, vec.size()) {
            if (x <= vec[i]) {
                cout << vec[i] << endl;
                return 0;
            }
        }
    }

    else if (x < 10000000) {
        vl vec = {1111111, 1234567, 2222222, 2345678, 3333333, 3456789, 4444444, 5555555, 6543210, 6666666, 7654321, 7777777, 8765432, 8888888, 9876543, 9999999};
        rep(i, vec.size()) {
            if (x <= vec[i]) {
                cout << vec[i] << endl;
                return 0;
            }
        }
    }

    else if (x < 100000000) {
        vl vec = {11111111, 12345678, 22222222, 23456789, 33333333, 4444444, 55555555, 66666666, 76543210, 77777777, 87654321, 88888888, 98765432, 99999999};
        rep(i, vec.size()) {
            if (x <= vec[i]) {
                cout << vec[i] << endl;
                return 0;
            }
        }
    }

    else if (x < 1000000000) {
        vl vec = {111111111, 123456789, 222222222, 333333333, 44444444, 555555555, 666666666, 777777777, 876543210, 888888888, 987654321, 999999999};
        rep(i, vec.size()) {
            if (x <= vec[i]) {
                cout << vec[i] << endl;
                return 0;
            }
        }
    }

    else if (x < 10000000000) {
        vl vec = {1111111111, 2222222222, 3333333333, 444444444, 5555555555, 6666666666, 7777777777, 8888888888, 9876543210, 9999999999};
        rep(i, vec.size()) {
            if (x <= vec[i]) {
                cout << vec[i] << endl;
                return 0;
            }
        }
    }

    else {
        string s = to_string(x);
        string s_ans;
        rep(i, s.size()) s_ans += '1';
        while (true) {
            ll ans = stoll(s_ans);
            if (x <= ans) {
                cout << ans << endl;
                return 0;
            }
            rep(i, s.size()) s_ans[i] = to_string((s_ans[i] - '0') + 1)[0];
        }
    }
}
