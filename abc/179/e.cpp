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
#define rep3(i, s, n) for (ll i = (ll)(s); i <= (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll n, x, m;
    cin >> n >> x >> m;

    vvl graph(m, vl(0));
    graph[x].push_back(1);

    vl vec(m+1);
    vl sum_vec(m+1);
    vec[1] = x;
    sum_vec[1] = x;

    ll ans = x;

    rep3(i, 2, n) {
        x = x * x % m;
        ans += x;
        vec[i] = x;
        sum_vec[i] = sum_vec[i - 1] + x;
        if (graph[x].size() == 0) graph[x].push_back(i);
        else {
            ll first = graph[x][0];
            ll difx = i - first;
            ll sumx = sum_vec[i] - sum_vec[first];
            ll rest = (n - i) % difx;

            ans += sumx * ((n - i) / difx);

            rep2(j, rest) {
                ans += vec[first + j];
            }
            break;
        }
    }

    cout << ans << endl;
}