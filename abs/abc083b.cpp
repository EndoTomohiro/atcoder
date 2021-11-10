#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int keta_sum(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int c = 0;
    rep(i, n) {
        if (keta_sum(i+1) >= a && keta_sum(i+1) <= b) c += i + 1;
    }

    cout << c << endl;
}