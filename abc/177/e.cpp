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

// 1 以上 N 以下の整数が素数かどうかを返す
vl Eratosthenes(int N) {
    // テーブル
    vl isprime(N+1, 0);

    // 1 は予めふるい落としておく
    isprime[1] = 1;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = p;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

bool setwise(vl a) {
    ll x = a[0];
    rep2(i, a.size() - 1) x = gcd(x, a[i]);
    if (x == 1) return true;
    else return false;
}

int main() {
    ll n;
    cin >> n;

    vl a(n);
    rep(i, n) cin >> a[i];

    vl isprime = Eratosthenes(1000000);

    vb used(1000000, false);

    rep(i, n) {
        ll x = a[i];
        vl vec;
        while (x > 1) {
            ll p = isprime[x];
            if (!p) p = x;
            vec.push_back(p);
            x /= p;
        }

        sort(all(vec));
        vec.erase(unique(all(vec)), vec.end());
        rep(j, vec.size()) {
            if (used[vec[j]]) {
                if (setwise(a)) puts("setwise coprime");
                else puts("not coprime");
                return 0;
            }
            used[vec[j]] = true;
        }

    }

    puts("pairwise coprime");
}