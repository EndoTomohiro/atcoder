#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int binary_search(int key, vector<int> s) {
    int left = 0;
    int right = s.size() - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (s[mid] == key) return mid;
        else if (s[mid] > key) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    rep(i, n) cin >> s[i];

    int q;
    cin >> q;

    vector<int> t(q);
    rep(i, q) cin >> t[i];

    int ans = 0;

    rep(i, q) {
        if (binary_search(t[i], s) != -1) ans++;
    }

    cout << ans << endl;
}