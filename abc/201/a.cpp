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
    ll a, b, c;
    cin >> a >> b >> c;
    
    vl vec1 = {a, b, c};
    vl vec2 = {a, c, b};
    vl vec3 = {b, a, c};
    vl vec4 = {b, c, a};
    vl vec5 = {c, a, b};
    vl vec6 = {c, b, a};

    vvl vec = {vec1, vec2, vec3, vec4, vec5, vec6};

    rep(i, 6) {
        if (vec[i][2] - vec[i][1] == vec[i][1] - vec[i][0]) {
            puts("Yes");
            exit(0);
        }
    }

    puts("No");
}