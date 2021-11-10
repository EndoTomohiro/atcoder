#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    vector<int> v(4);
    v[0] = n / 1000;
    v[1] = (n % 1000) / 100;
    v[2] = (n % 100) / 10;
    v[3] = n % 10;

    rep(i, 1 << 3) {
        bitset<3> op(i);
        int ans = v[0];

        rep(j, 3) {
            if (op.test(j)) ans += v[j+1];
            else ans -= v[j+1];
        }

        if (ans == 7) {
            cout << v[0];
            rep(j, 3) {
                if (op.test(j)) cout << '+';
                else cout << '-';
                cout << v[j+1];
            }
            cout << '=' << '7' << endl;
            break;
        }
    }
}