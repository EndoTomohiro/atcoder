#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n, s, d;
    cin >> n >> s >> d;

    vector< pair<int, int> > xy(n);
    int count = 0;
    rep(i, n) {
        cin >> xy[i].first >> xy[i].second;
        if (xy[i].first < s && xy[i].second > d) count++;
    }

    if (count > 0) cout << "Yes" << endl;
    else cout << "No" << endl;

}