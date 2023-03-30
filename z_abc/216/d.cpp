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
using vql = vector<ql>;
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

bool compare(vl a, vl b) {
    if (a.size() == 0) return false;
    if (b.size() == 0) return true;
    return a[a.size() - 1] < b[b.size() - 1];
}

int main() {
    ll n, m;
    cin >> n >> m;

    ql que;
    vql a(m);
    vvl mem(n);


    vvl graph(m, vl(0));

    rep(i, m) {
        ll k;
        cin >> k;
        rep(j, k) {
            ll aj;
            cin >> aj;
            a[i].push(aj - 1);
        }
        mem[a[i].front()].push_back(i);
    }

    rep(i, n) {
        if (mem[i].size() == 2) que.push(i);
    }

    while (!que.empty()) {
        ll now = que.front();
        que.pop();

        for (auto p : mem[now]) {
            a[p].pop();
            if (!a[p].empty()) {
                mem[a[p].front()].push_back(p);
                if (mem[a[p].front()].size() == 2) {
                    que.push(a[p].front());
                }
            }
        }
    }

    for (auto p : a) {
        if (!p.empty()) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}