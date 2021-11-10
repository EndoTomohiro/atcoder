#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector< tuple<string, int, int> > sp(n);

    rep(i, n) {
        string s;
        int p;
        cin >> s >> p;
        get<0>(sp[i]) = s;
        get<1>(sp[i]) = 100 - p;
        get<2>(sp[i]) = i + 1;
    }

    sort(sp.begin(), sp.end());

    rep(i, n) cout << get<2>(sp[i]) << endl;
}