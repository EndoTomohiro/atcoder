#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > ab(n);
    vector<pair<int, int> > rev(n);

    rep(i, n) {
        cin >> ab[i].first;
        cin >> ab[i].second;
        rev[i].first = ab[i].second;
        rev[i].second = ab[i].first;
    }

    sort(rev.begin(), rev.end());

    rep(i, n) {
        cout << rev[i].second << " " << rev[i].first << endl;
    }
}