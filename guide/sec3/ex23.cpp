#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;
    rep(i, n) {
        int a;
        cin >> a;
        pq.push(a);
    }

    int count = 0;
    int max = 0;
    int num = pq.top();
    int max_num;
    rep(i, n) {
        if (pq.top() == num) count++;
        else {
            if (count > max) {
                max = count;
                max_num = num;
            }
            num = pq.top();
            count = 1;
        }
        pq.pop();
    }

    if (count > max) {
        max = count;
        max_num = num;
    }

    cout << max_num << " " << max << endl;
}