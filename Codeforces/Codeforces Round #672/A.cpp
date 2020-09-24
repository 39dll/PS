#include <bits/stdc++.h>
using namespace std;
int main() {
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int T; cin >> T;
   while (T--) {
      int N;
      cin >> N;
      vector<int> v(N);
      for (int i = 0; i < N; ++i) cin >> v[i];
      int cnt = 0;
      for (int i = 1; i < N; ++i) {
         if (v[i] < v[i - 1]) {
            cnt += 1;
         }
      }
      if (cnt == N - 1) {
         cout << "NO" << '\n';
      }
      else {
         cout << "YES" << '\n';
      }
   }
}
