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

int vec[95][95];

int f(int ans, int i, int j, int vec[95][95]) {
    if (i < 0 || j < 0 || !vec[i][j]) return ans;

    ans++;
    vec[i][j] = 0;
    int up = f(ans, i-1, j, vec);
    int down = f(ans, i+1, j, vec);
    int left = f(ans, i, j-1, vec);
    int right = f(ans, i, j+1, vec);

    vec[i][j] = 1;

    return max({up, down, left, right});
}

int main() {
    int m, n;
    cin >> m >> n;
    rep(i, n) rep(j, m) cin >> vec[i][j];

    int ans = 0;
    rep(i, n) rep(j, m) {
        int vec2[95][95];
        memcpy(vec2, vec, sizeof(vec));
        chmax(ans, f(0, i, j, vec2));
    }

    cout << ans << endl;
}