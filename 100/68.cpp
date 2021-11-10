#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, s, n) for (long long i = (long long)(s); i < (long long)(n); i++)
#define rep3(i, s, n) for (long long i = (long long)(n); i >= (long long)(s); i--)
const long long INF = 1000000000000000;
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    int n;
    cin >> n;

    cout << n << ':';

    int x = 2;
    while (x * x <= n) {
        if (n % x == 0) {
            cout << ' ' << x;
            n /= x;
        }
        else x++;
    }

    if (n != 1) cout << ' ' << n;

    cout << endl;
}