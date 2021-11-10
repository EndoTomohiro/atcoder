#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int ctoi(char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}

int main() {
    string s;
    cin >> s;

    if (s.size() == 1) {
        char s1 = s[0];
        if (ctoi(s1) == 8) puts("Yes");
        else puts("No");
    }

    else if (s.size() == 2) {
        int s_int = stoi(s);
        int s1 = s_int % 10;
        int s10 = (s_int - s1) / 10;
        if (s_int % 8 == 0 || (s1 * 10 + s10) % 8 == 0) puts("Yes");
        else puts("No");
    }

    else {
        vector<int> vec(10, 0);
        rep(i, s.size()) vec[ctoi(s[i])]++;

        rep2(i, 13, 125) {
            vector<int> vec2 = vec;
            int i8 = i * 8;
            bool ok = true;
            while (i8 > 0) {
                vec2[i8 % 10]--;
                if (vec2[i8 % 10] < 0) {
                    ok = false;
                    break;
                }
                i8 /= 10;
            }
            if (ok) {
                puts("Yes");
                return 0;
            }
        }

        puts("No");
    }
}