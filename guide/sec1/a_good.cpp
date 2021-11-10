#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int n1, n2, n3, n4;
    n1 = (n - n % 1000) / 1000;
    n2 = (n % 1000 - n % 100) / 100;
    n3 = (n % 100 - n % 10) / 10;
    n4 = n % 10;
    if ((n1 == n2 && n2 == n3) || (n2 == n3 && n3 == n4)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}