#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x = 0;
    cin >> n;
    for (int i=0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        x += r - l + 1;
    }
    cout << x << endl;
}