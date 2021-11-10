#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    string s;
    cin >> s;

    string ok = "YES";

    while (s.size()) {
        bool ok2 = false;
        if (s.size() >= 7) {
            string s7 = "";
            rep2(i, s.size()-7, s.size()) s7.push_back(s[i]);
            if (s7 == "dreamer") {
                rep(i, 7) s.pop_back();
                ok2 = true;
            }
        }

        if (s.size() >= 6 && !ok2) {
            string s6 = "";
            rep2(i, s.size()-6, s.size()) s6.push_back(s[i]);
            if (s6 == "eraser") {
                rep(i, 6) s.pop_back();
                ok2 = true;
            }
        }

        if (s.size() >= 5 && !ok2) {
            string s5 = "";
            rep2(i, s.size()-5, s.size()) s5.push_back(s[i]);
            if (s5 == "erase" || s5 == "dream") {
                rep(i, 5) s.pop_back();
                ok2 = true;
            }
        }

        if (!ok2) {
            ok = "NO";
            break;
        }
    }

    cout << ok << endl;
}