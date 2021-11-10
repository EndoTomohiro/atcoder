#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));

    int s = 0;
    int c = 0;
    while(a.size() > 0) {
        if (c % 2 == 0) s += a[a.size()-1];
        else s -= a[a.size()-1];
        c++;
        a.pop_back();
    }

    cout << s << endl;
}