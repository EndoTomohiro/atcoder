#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n;
    int n, m;
    cin >> n >> m;

    vector< pair<int, int> > xy(m);
    rep(i, m) {
        cin >> xy[i].first >> xy[i].second;
    }

    int max_num = 1;
    rep(i, 1 << 12) {
        bitset<12> bit(i);
        int num = 0;
        vector<int> vec(0);

        rep(j, n) {
            if (bit.test(j)) {
                num++;
                vec.push_back(j+1);
            }
        }

        bool ok3 = true;

        rep(j, num-1) {
            bool ok2 = true;
            for (int k = j+1; k < num; k++) {
                pair<int, int> p(vec[j], vec[k]);

                bool ok = false;
                rep(l, m) {
                    if (p == xy[l]) {
                        ok = true;
                        break;
                    }
                }

                if (!ok) {
                    ok2 = false;
                    break;
                }
            }

            if (!ok2) {
                ok3 = false;
                break;
            } 
        }

        if (ok3) max_num = max(max_num, num);
    }

    cout << max_num << endl;
}