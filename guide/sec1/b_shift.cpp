#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x = 100;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, y = 0;
        cin >> a;
        while (a % 2 == 0) {
            a /= 2;
            y++;
        }
        x = min(x, y);
    }
    cout << x << endl;
}