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
    /*
    std::set<int> st{8, 1, 4};
    auto itr = st.end();
    --itr;
    std::cout << *itr << "\n";
    return 0;
    */

    ll q;
    cin >> q;

    ll n = 1 << 20;
    vl a(n, -1);

    set<pl> st;
    st.insert(make_pair(0, n));

    vl ans;

    rep(i, q) {
        ll t, x;
        cin >> t >> x;

        if (t == 1) {
            ll h = x % n;
            auto itr = st.end();
            itr--;
            ll ln = (*itr).first;
            ll rn = (*itr).second;

            if (rn <= h) {
                ll l1 = (*st.begin()).first;
                ll r1 = (*st.begin()).second;
                ll p = l1;
                
                a[p] = x;
                st.erase(*st.begin());
                if (l1 + 1 < r1) st.insert(make_pair(l1 + 1, r1));
            }
            else {
                auto itr_upper = st.upper_bound(make_pair(h, 0));
                ll lm = (*itr_upper).first;
                ll rm = (*itr_upper).second;
                if (ln < h) {
                    lm = ln;
                    rm = rn;
                }
                if (h < lm) {
                    itr_upper--;
                    ll lm2 = (*itr_upper).first;
                    ll rm2 = (*itr_upper).second;
                    if (lm2 <= h && h < rm2) {
                        lm = lm2;
                        rm = rm2;
                    }
                }
                // cout << "lm; " << lm << endl;
                // cout << "rm; " << rm << endl;
                ll p = max(h, lm);
                a[p] = x;
                st.erase(make_pair(lm, rm));
                if (lm < p) st.insert(make_pair(lm, p));
                if (p + 1 < rm) st.insert(make_pair(p + 1, rm));
            }
        }
        else {
            ans.push_back(a[x % n]);
        }
    }

    rep(i, ans.size()) cout << ans[i] << endl;
}
