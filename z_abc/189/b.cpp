#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> v(n), p(n);
    rep(i, n) {
        cin >> v[i] >> p[i];
    }

    int al = 0, count = -1;
    rep(i, n) {
        al += v[i] * p[i];
        if (al > 100 * x) {
            count = i + 1;
            break;
        }
    }

    cout << count << endl;
}
