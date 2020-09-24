#include <bits/stdc++.h>
using namespace std;
int main() {
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int T; cin >> T;

   while (T--) {
      int N, Q; cin >> N >> Q;
      vector<int> v(N);
      long long ans = 0;
      bool p = 1;
      for (int i = 0; i < N; i++) cin >> v[i];
      for (int i = 0; i < N; i++) {
         if (p) {
            if (i == 0 || v[i] > v[i - 1]) {
               if (i == N - 1 || v[i] > v[i + 1]) {
                  ans += v[i];
                  p = 0;
               }
            }
         }
         else {
            if (i == N - 1) break;
            if (i == 0 || v[i] < v[i - 1]) {
               if (v[i] < v[i + 1]) {
                  ans -= v[i];
                  p = 1;
               }
            }
         }
      }
      cout << ans << "\n";
   }
}
