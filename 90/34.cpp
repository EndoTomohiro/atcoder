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
    int n, k;
    cin >> n >> k;

    vl a(n);
    rep(i, n) cin >> a[i];

    vl ans(n);
    ll cnt = 0;
    map<ll, ll> Map;

    while (true) {
        if (Map[a[ans[0]]] > 0) Map[a[ans[0]]]++;
        else {
            if (cnt == k) {
                ans[0]--;
                break;
            }
            Map[a[ans[0]]] = 1;
            cnt++;
        }
        if (ans[0] == n - 1) break;
        ans[0]++;
    }

    rep2(i, 1, n) {
        if (ans[i-1] == n - 1) {
            ans[i] = n - 1;
            continue;
        }
        ans[i] = ans[i-1] + 1;
        if (Map[a[i-1]] == 1) cnt--;
        Map[a[i-1]]--;

        while (true) {
            if (Map[a[ans[i]]] > 0) Map[a[ans[i]]]++;
            else {
                if (cnt == k) {
                    ans[i]--;
                    break;
                }
                Map[a[ans[i]]] = 1;
                cnt++;
            }
            if (ans[i] == n - 1) break;
            ans[i]++;
        }
    }

    rep(i, n) ans[i] -= i - 1;

    cout << *max_element(all(ans)) << endl;
}