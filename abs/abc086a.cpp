#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int a, b;
    cin >> a >> b;

    if (a * b % 2 != 0) cout << "Odd" << endl;
    else cout << "Even" << endl;
}