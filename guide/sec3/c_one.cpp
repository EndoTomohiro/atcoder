#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n, m;
    cin >> n >> m;

    vector< pair<int, int> > ab(m);
    rep(i, m) {
        cin >> ab[i].first >> ab[i].second;
    }

    vector<int> v(n);
    rep(i, n) {
        v[i] = i + 1;
    }
    // sort(v.begin(), v.end());

    int count = 0;

    do {
        bool ok2 = true;
        rep(i, n-1) {
            bool ok = false;
            pair<int, int> p(v[i], v[i+1]);
            pair<int, int> q(v[i+1], v[i]);
            rep(j, m) {
                if (p == ab[j] || q == ab[j]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                ok2 = false;
                break;
            }
        }
        if (ok2) count++;
    } while (next_permutation(v.begin() + 1, v.end()));

    cout << count << endl;
}