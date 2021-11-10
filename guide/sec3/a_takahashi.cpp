#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    rep(i, n) {
        cin >> t[i];
    }

    int min_time = 200;
    rep(i, 1 << 4) {
        bitset<4> bit(i);
        int niku1 = 0;
        int niku2 = 0;

        rep(j, n) {
            if (bit.test(j)) niku1 += t[j];
            else niku2 += t[j];
        }

        int time = max(niku1, niku2);
        min_time = min(min_time, time);
    }

    cout << min_time << endl;
}