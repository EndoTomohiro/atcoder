#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using dl = deque<ll>;
using pri = priority_queue< ll, vl, greater<ll> >;
using vp = vector<pri>;
using ml = map<ll, ll>;
using sl = set<ll>;
using msl = multiset<ll>;
using vse = vector<sl>;
using vmu = vector<msl>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 998244353;
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
    ll n, q;
    cin >> n >> q;

    vmu box(n+1);
    vse card(200010);
    rep(i, q) {
        ll t, x;
        cin >> t >> x;
        if (t == 1) {
            ll y;
            cin >> y;
            box[y].insert(x);
            card[x].insert(y);
        }
        else if (t == 2) {
            for (auto itr = box[x].begin(); itr != box[x].end(); ++itr) {
                cout << *itr << ' ';
            }
            cout << endl;
        }
        else {
            for (auto itr = card[x].begin(); itr != card[x].end(); ++itr) {
                cout << *itr << ' ';
            }
            cout << endl;
        }
    }
}
