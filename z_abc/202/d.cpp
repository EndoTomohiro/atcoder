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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

ll f(ll x, ll a){
    ll sum = 1;
    ll ac = 1;
    rep2(i, x-a+1, x) {
        sum *= i;
        while (ac <= a && sum % ac == 0) {
            sum /= ac;
            ac++;
        }
    }
    return sum;
}

int main() {
    ll a, b, k;
    cin >> a >> b >> k;

    ll an = a, bn = b;
    string ans;

    rep(i, a+b) {
        if (an == 0) {
            ans += 'b';
            bn--;
        }
        else if (bn == 0) {
            ans += 'a';
            an--;
        }
        else {
            ll pat = f(a+b-1-i, an-1);
            if (pat < k) {
                ans += 'b';
                k -= pat;
                bn--;
            }
            else {
                ans += 'a';
                an--;
            }
        }
    }

    cout << ans << endl;
}
