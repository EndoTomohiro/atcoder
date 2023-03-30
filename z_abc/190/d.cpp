#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    ll n;
    cin >> n;

    while (n % 2 == 0) n /= 2;
    ll sq = sqrt(n), ans = 0;

    for (ll i = 1; i <= sq; i++) if (n % i == 0) ans += 2;
    if (sq * sq == n) ans--;

    cout << ans * 2 << endl;
}