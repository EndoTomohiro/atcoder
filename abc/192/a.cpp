#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int x;
    cin >> x;

    cout << 100 - x % 100 << endl;
}