#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
#define pi 3.14159265359;
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
    int n;
    cin >> n;

    int c = 0;
    rep2(i, 1, n+1) {
        if (i % 2 == 1) {
            int k = 0;
            rep2(j, 1, 15) {
                if (j * j > i) break;
                else if (i > j && i % j == 0) {
                    if (j * j == i) k += 1;
                    else k += 2;
                }
            }
            if (k == 8) c++;
        }
    }

    cout << c << endl;
}