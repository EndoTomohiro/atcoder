#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n, m;
    cin >> n >> m;

    vector< pair<int, int> > ab(m);
    rep(i, m) cin >> ab[i].first >> ab[i].second;

    int k;
    cin >> k;

    vector< pair<int, int> > cd(k);
    rep(i, k) cin >> cd[i].first >> cd[i].second;
    
    int ok_max = 0;

    rep(i, 1 << 16) {
        bitset<16> bit(i);
        vector<int> count(n);

        rep(j, k) {
            if (bit.test(j)) count[cd[j].first - 1]++;
            else count[cd[j].second - 1]++;
        }

        int ok = 0;
        rep(j, m) {
            if (count[ab[j].first - 1] > 0 && count[ab[j].second - 1] > 0) ok++;
        }

        ok_max = max(ok_max, ok);
    }

    cout << ok_max << endl;
}