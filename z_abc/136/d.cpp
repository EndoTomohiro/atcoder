#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using ql = queue<ll>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
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

    ll n = s.size();
    ll j = 0;
    vl vec(n);
    rep(i, n) {
        if (s[i] == 'L') {
            if (s[i - 1] == 'L') {
                if ((i - 1 - j) % 2) vec[j]++;
                else vec[j - 1]++;
            }
        }
        else if (s[i + 1] == 'R') {
            vec[i + 1] = vec[i] + 1;
            vec[i] = 0;
        }
        else {
            vec[i + 1] = (vec[i] + 1) / 2 + 1;
            vec[i] = vec[i] / 2 + 1;
            j = i + 1;
        }
    }

    rep(i, n) cout << vec[i] << ' ';
    cout << endl;
}
