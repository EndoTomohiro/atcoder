#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
const long long INF = 1000000000000000;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, s, n) for (long long i = (long long)(s); i < (long long)(n); i++)
#define rep3(i, s, n) for (long long i = (long long)(n); i >= (long long)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

const long long x = 1000000007;

int main() {
    int m, n;
    cin >> m >> n;

    vector<long long> amari(30);
    amari[0] = m;
    rep2(i, 1, 30) amari[i] = amari[i-1] * amari[i-1] % x;

    long long ans = 1;

    bitset<30> s(n);
    rep(i, 30) {
        if (s.test(i)) {
            ans = ans * amari[i] % x;
        }
    }

    cout << ans << endl;
}