#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    int orange_max = 0;
    rep(i, n) {
        int orange = a[i];
        int x = a[i];
        int count = 1;
        for(int j = i+1; j < n;j++) {
            x = min(x, a[j]);
            if (orange < x * (j - i + 1)) {
                orange = x * (j - i + 1);
            }
        }
        orange_max = max(orange_max, orange);
    }

    cout << orange_max << endl;
}