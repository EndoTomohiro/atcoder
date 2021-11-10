#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n;
    cin >> n;

    vector<int> d(n);
    rep(i, n) cin >> d[i];

    sort(all(d));

    int c = n;
    rep(i, n-1) {
        if (d[i] == d[i+1]) c--;
    }

    cout << c << endl;
}