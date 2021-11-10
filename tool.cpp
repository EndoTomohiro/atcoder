#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector<pl>;
using vs = vector<string>;
using vvl = vector<vl>;
using ql = queue<ll>;
const double pi = 3.14159265359;
const ll INF = 1000000000000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep4(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}


// 桁数
ll ketasu(ll x) {
    ll keta = 0, num = x;
    while (num != 0) {
        num /= 10;
        keta++;
    }
    return keta;
}

// 各桁の値の合計
ll keta_sum(ll n) {
    ll s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

// 10進数を2進数に変換
ll binary(ll n){
    ll ans = 0;
    for (ll i = 0; n > 0; i++)
    {
        ans += (n % 2) * pow(10, i);
        n /= 2;
    }
    return ans;
}

int main() {
    // 小数点以下10桁表示
    double x;
    cout << fixed << setprecision(11);
    cout << x << endl;

    // char型をll型に変換
    char c;
    ll ll_c = c - '0';

    // 切り上げ
    ll a, b;
    ll ceil = (a + b - 1) / b;

    // 配列のコピー
    vl vec1, vec2;
    copy(all(vec1), vec2.begin());

    // 大きい順にソート
    vl vec;
    sort(all(vec), greater<ll>());

    // 配列の最大値
    vl vec;
    ll max_range = *max_element(all(vec));

    // 二分探索
    vl vec;
    ll key;
    // keyより小さい要素の数
    ll less = lower_bound(all(vec), key) - vec.begin();
    // key以下の要素の数
    ll less_equal = upper_bound(all(vec), key) - vec.begin();
    // key以上の要素の数
    ll more_equal = vec.end() - lower_bound(all(vec), key);
    // keyより大きい要素の数
    ll more = vec.end() - upper_bound(all(vec), key);
    
    // 部分文字列
    string s;
    ll l, r;
    // l文字目以降の部分文字列
    string ans_mae = s.substr(l);
    // l文字目から長さrの部分文字列
    string ans_ato = s.substr(l, r);

    // 配列の重複を削除
    vl vec;
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());

    // 配列の要素数を変更
    ll n;
    vl vec;
    vec.resize(n);

    // 配列の中のnの個数
    ll n;
    vl vec;
    ll c = count(all(vec), x);

    // 順序付き集合
    set<int> st;
    st.insert(0);

    // 大きい順のキュー
    priority_queue<ll> que1;
    // 小さい順のキュー
    priority_queue< ll, vl, greater<ll> > que2;
    que1.push(0);

    // map
    map<string, ll> Map;
    Map["abc"] = 0;

    // 順列全探索
    vl vec;
    do {
        // Todo
    } while (next_permutation(all(vec)));

    // 90度回転
    pl pair;
    ll x = pair.first;
    ll y = pair.second;
    pair = make_pair(y, -x);

    // 論理和
    ll a, b;
    ll aandb = a & b;
    ll aorb = a | b;
    ll axorb = a ^ b;

}


/*
#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265359;
const long long INF = 1000000000000000;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, s, n) for (long long i = (long long)(s); i < (long long)(n); i++)
#define rep3(i, s, n) for (long long i = (long long)(n); i >= (long long)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}
*/
