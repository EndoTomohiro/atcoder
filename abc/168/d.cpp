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
using qp = queue<pl>;
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

    vl vec(n, -1);
    
    ql que;
    que.push(0);

    while(!que.empty()) {
        ll pos = que.front();
        que.pop();

        rep(i, graph[pos].size()) {
            ll next = graph[pos][i];
            if (vec[next] != -1) continue;
            vec[next] = pos;
            que.push(next);
        }
    }

    rep2(i, vec.size() - 1) {
        if (vec[i] == -1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    rep2(i, vec.size() - 1) cout << vec[i] + 1 << endl;
}
