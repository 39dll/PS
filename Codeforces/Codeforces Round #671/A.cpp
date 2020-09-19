#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int t;
        vector<int> arr;
        cin >> t;
        for (int i = 0; i < t; i++) {
            char a;
            cin >> a;
            arr.push_back(a - '0');
        }
        bool rw = 0, bw = 0;
        for (int i = 0; i < t; i++) {
            if (i % 2 == 0) {
                if (arr[i]%2 == 1) rw = 1;
            }
            else {
                if (arr[i]%2 == 0) bw = 1;
            }
        }
        if (t % 2 == 0) {
            cout << (bw ? 2 : 1);
        }
        else cout << (rw ? 1 : 2);
        cout << '\n';
    }
}
