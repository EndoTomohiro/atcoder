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
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
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
    ll h, w, n, m;
    cin >> h >> w >> n >> m;

    vvl light_h(h, vl(0));
    vvl light_w(w, vl(0));
    vvl block_h(h, vl(0));
    vvl block_w(w, vl(0));

    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        light_h[a].push_back(b);
        light_w[b].push_back(a);
    }

    rep(i, m) {
        ll c, d;
        cin >> c >> d;
        c--; d--;
        block_h[c].push_back(d);
        block_w[d].push_back(c);
    }

    rep(i, h) {
        sort(all(light_h[i]));
        sort(all(block_h[i]));
    }

    rep(j, w) {
        sort(all(light_w[j]));
        sort(all(block_w[j]));
    }


    ll ans = 0;

    rep(i, h) rep(j, w) {
        if (light_h[i].size() == 0 && light_w[j].size() == 0) {
            continue;
        }
        else if ((light_h[i].size() >= 1 && block_h[i].size() == 0) || (light_w[j].size() >= 1 && block_w[j].size() == 0)) ans++;
        else {
            ll lh_less = lower_bound(all(light_h[i]), j) - light_h[i].begin();
            ll lw_less = lower_bound(all(light_w[j]), i) - light_w[j].begin();
            ll bh_less = lower_bound(all(block_h[i]), j) - block_h[i].begin();
            ll bw_less = lower_bound(all(block_w[j]), i) - block_w[j].begin();

            if (light_h[i].size() > lh_less && light_h[i][lh_less] == j) ans++;
            else if (block_h[i].size() > bh_less && block_h[i][bh_less] == j) continue;
            else if (lh_less >= 1 && (bh_less == 0 || light_h[i][lh_less-1] > block_h[i][bh_less-1])) ans++;
            else if (lw_less >= 1 && (bw_less == 0 || light_w[j][lw_less-1] > block_w[j][bw_less-1])) ans++;
            else if (lh_less < light_h[i].size() && (bh_less == block_h[i].size() || light_h[i][lh_less] < block_h[i][bh_less])) ans++;
            else if (lw_less < light_w[j].size() && (bw_less == block_w[j].size() || light_w[j][lw_less] < block_w[j][bw_less])) ans++;
        }
    }

    cout << ans << endl;
}