#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int m;
    cin >> m;
    vector<string> t(m);
    for (int i = 0; i < m; i++) cin >> t[i];

    int x = 0;
    for (int i = 0; i < n; i++) {
        int y = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == s[i]) y++;
        }
        for (int j = 0; j < m; j++) {
            if (t[j] == s[i]) y--;
        }
        x = max(x, y);
    }

    cout << x << endl;
}