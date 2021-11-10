#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    vector<int> n(1), x(1);
    cin >> n[0] >> x[0];

    while (n[n.size() - 1] != 0) {
        int ni, xi;
        cin >> ni >> xi;

        n.push_back(ni);
        x.push_back(xi);
    }

    rep(i, n.size() - 1) {
        int ans = 0;
        rep2(j, 1, n[i]-1) rep2(k, j+1, n[i]) rep2(l, k+1, n[i]+1) {
            if (j != k && k != l && l != j && j + k + l == x[i]) ans++;
        }
        cout << ans << endl;
    }
}