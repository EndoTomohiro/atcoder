#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vc = vector<char>;
using vvl = vector<vl>;
using dl = deque<ll>;
using pri = priority_queue<ll>;
using ml = map<ll, ll>;
using sl = set<ll>;
using msl = multiset<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
const ll dif = 998244353;
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

// 1 以上 N 以下の整数が素数かどうかを返す(計算量NloglogN)
vb Eratosthenes(int N) {
    // テーブル
    vb isprime(N+1, true);

    // 1 は予めふるい落としておく
    isprime[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main() {
    ll n;
    cin >> n;
    vb isprime = Eratosthenes(400000);
    vl prime;
    rep2(i, 400000) {
        if (isprime[i]) prime.push_back(i);
    }
    ll m = isprime.size();
    ll ans = 0;
    rep(i, m-2) {
        ll a = prime[i];
        if (a * a * a * a * a > n) break;
        rep3(j, i+1, m-1) {
            ll b = prime[j];
            if (a * a * b * b * b > n) break;
            rep3(k, j+1, m) {
                ll c = prime[k];
                if (a * a * b * c * c > n) break;
                ans++;
            }
        }
    }
    cout << ans << endl;

}
