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
    ll n, m;
    cin >> n >> m;

    vvl vec(n, vl(0));
    vvl rev(n, vl(0));
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        vec[a].push_back(b);
        rev[b].push_back(a);
    }

    rep(i, n) {
        sort(all(vec[i]));
        vec[i].erase(unique(all(vec[i])), vec[i].end());
        sort(all(rev[i]));
        rev[i].erase(unique(all(rev[i])), rev[i].end());
    }

    vl leng(n);
    rep(i, n) leng[i] = rev[i].size();

    vl cnt(n);

    set<ll> st;
    rep(i, n) {
        if (leng[i] == 0) st.insert(i);
    }

    vl ans;

    while (!st.empty()) {
        ll top = *st.begin();
        ans.push_back(top + 1);
        st.erase(top);

        rep(i, vec[top].size()) {
            ll k = vec[top][i];
            cnt[k]++;
            if (cnt[k] == leng[k]) st.insert(k);
        }
    }

    if (ans.size() != n) {
        cout << -1 << endl;
        return 0;
    }

    rep(i, n) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}