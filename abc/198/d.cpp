#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<char, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using ql = queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
using dl = deque<ll>;
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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vc vec;
    rep(i, s1.size()) vec.push_back(s1[i]);
    rep(i, s2.size()) vec.push_back(s2[i]);
    rep(i, s3.size()) vec.push_back(s3[i]);
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());

    if (vec.size() > 10) {
        puts("UNSOLVABLE");
        return 0;
    }

    while (vec.size() < 10) {
        vec.push_back('{');
    }

    do {
        if (s1[0] == vec[0] || s2[0] == vec[0] || s3[0] == vec[0]) continue;
        ll n1 = 0, n2 = 0, n3 = 0;
        rep(i, s1.size()) {
            rep(j, 10) {
                if (s1[i] == vec[j]) {
                    n1 = n1 * 10 + j;
                    break;
                }
            }
        }
        rep(i, s2.size()) {
            rep(j, 10) {
                if (s2[i] == vec[j]) {
                    n2 = n2 * 10 + j;
                    break;
                }
            }
        }
        rep(i, s3.size()) {
            rep(j, 10) {
                if (s3[i] == vec[j]) {
                    n3 = n3 * 10 + j;
                    break;
                }
            }
        }
        if (n1 + n2 == n3) {
            cout << n1 << endl;
            cout << n2 << endl;
            cout << n3 << endl;
            return 0;
        }
    } while (next_permutation(all(vec)));

    puts("UNSOLVABLE");
}
