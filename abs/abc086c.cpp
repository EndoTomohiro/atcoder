#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n;
    cin >> n;

    vector< tuple<int, int, int> > txy(n);
    get<0>(txy[0]) = 0;
    get<1>(txy[0]) = 0;
    get<2>(txy[0]) = 0;
    rep2(i, 1, n+1) cin >> get<0>(txy[i]) >> get<1>(txy[i]) >> get<2>(txy[i]);

    string ok = "Yes";
    rep(i, n) {
        int t = get<0>(txy[i+1]) - get<0>(txy[i]);
        int x = abs(get<1>(txy[i+1]) - get<1>(txy[i]));
        int y = abs(get<2>(txy[i+1]) - get<2>(txy[i]));

        if (t - x - y < 0 || t % 2 != (x + y) % 2) {
            ok = "No";
            break;
        }
    }

    cout << ok << endl;
}