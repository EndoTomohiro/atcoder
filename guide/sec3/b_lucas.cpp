#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 2; i <= (int)(n); i++)

int main() {
    int n;
    cin >> n;

    vector<int64_t> l(n+1);
    l[0] = 2;
    l[1] = 1;

    rep(i, n) l[i] = l[i-1] + l[i-2];

    cout << l[n] << endl;
}