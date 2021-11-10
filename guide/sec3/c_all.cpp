#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int d, g;
    cin >> d >> g;

    vector<int> p(d), c(d), s(d);
    rep(i, d) {
        cin >> p[i] >> c[i];
        s[i] = (i + 1) * 100 * p[i] + c[i];
    }

    int min_num = 1000;
    rep(i, 1 << 10) {
        bitset<10> bit(i);
        int sum = 0;
        int num = 0;

        rep(j, d) {
            if (bit.test(j)) {
                sum += s[j];
                num += p[j];
            }
        }

        if (sum >= g) min_num = min(min_num, num);

        else {
            rep(k, d) {
                if (!bit.test(d-1-k)) {
                    if (sum + 100 * (d - k) * (p[d-k-1] - 1) >= g) {
                        num += (g - sum + 100 * (d - k) - 1) / (100 * (d - k));
                        min_num = min(min_num, num);
                    }
                    break;
                }
            }
        }
    }
    cout << min_num << endl;
}