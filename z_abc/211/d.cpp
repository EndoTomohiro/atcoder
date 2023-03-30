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
const ll inf = 1000000000000000;
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
    ll n, m;
    cin >> n >> m;

    vvl graph(n, vl(0));
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vb used(n, false);
    vl kosu(n);

    used[0] = true;
    kosu[0] = 1;

    rep(i, graph[0].size()) {
        used[graph[0][i]] = true;
        kosu[graph[0][i]] = 1;
    }

    if (used[n-1]) {
        cout << 1 << endl;
        exit(0);
    }

    vl list = graph[0];
    while (!used[n-1]) {
        if (list.size() == 0) {
            cout << 0 << endl;
            exit(0);
        }
        vl next_list(0);
        rep(i, list.size()) {
            ll x = list[i];
            rep(j, graph[x].size()) {
                ll key = graph[x][j];
                if (!used[key]) {
                    next_list.push_back(key);
                    kosu[key] += kosu[x];
                    kosu[key] %= 1000000007;
                }
            }
        }
        sort(all(next_list));
        next_list.erase(unique(all(next_list)), next_list.end());
        list = next_list;
        rep(i, list.size()) used[list[i]] = true;
    }

    cout << kosu[n-1] << endl;
}