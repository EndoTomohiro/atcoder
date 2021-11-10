#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int i = 1, x = 0;
    for (int j = 0; j < n; j++) {
        i = a[i - 1];
        x++;
        if (i == 2) {
            cout << x << endl;
            break;
        }
    }

    if (i != 2) cout << -1 << endl;
}