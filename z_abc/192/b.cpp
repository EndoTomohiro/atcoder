#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    string s;
    cin >> s;

    string yn = "Yes";
    rep(i, s.size()) {
        if ((i % 2 == 0 && s[i] <= 90) || (i % 2 == 1 && s[i] >= 97)) {
            yn = "No";
            break;
        } 
    }

    cout << yn << endl;
}