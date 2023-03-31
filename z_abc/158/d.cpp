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
using sl = set<ll>;
using dc = deque<char>;
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
    string s;
    cin >> s;

    dc deq;
    rep(i, s.size()) deq.push_back(s[i]);

    ll q;
    cin >> q;

    bool ok = true;
    rep(i, q) {
        ll t;
        cin >> t;
        if (t == 1) ok = !ok;
        else {
            ll f;
            char c;
            cin >> f >> c;
            if (f == 1) {
                if (ok) deq.push_front(c);
                else deq.push_back(c);
            }
            else {
                if (!ok) deq.push_front(c);
                else deq.push_back(c);
            }
        }
    }

    while (!deq.empty()) {
        char c;
        if (ok) {
            c = deq.front();
            deq.pop_front();
        }
        else {
            c = deq.back();
            deq.pop_back();
        }
        cout << c;
    }
    cout << endl;
}