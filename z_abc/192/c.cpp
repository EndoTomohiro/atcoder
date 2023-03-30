#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int pow10(int n) {
    int pow = 1;
    rep(i, n) {
        pow *= 10;
    }
    return pow;
}

int f(int x) {
    int keta = 0, num = x;
    while (num != 0) {
        num /= 10;
        keta++;
    }

    vector<int> vec(keta);
    rep(i, keta) vec[i] = x / pow10(i) % 10;

    sort(vec.begin(), vec.end());
    int g1 = 0;
    rep(i, keta) {
        g1 += vec[i] * pow10(i);
    }

    reverse(vec.begin(), vec.end());
    int g2 = 0;
    rep(i, keta) {
        g2 += vec[i] * pow10(i);
    }

    return g1 - g2;

}
int main() {
    int n, k;
    cin >> n >> k;

    int x = n;
    rep(i, k) {
        x = f(x);
    }

    cout << x << endl;
}