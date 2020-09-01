#include <bits/stdc++.h>
using namespace std;
int N, arr[8001], psum[8001];
int main() {
   int T; cin >> T;
   while (T--) {
      cin >> N;
      for (int i = 1; i <= N; i++) {
         cin >> arr[i];
         psum[i] = psum[i - 1] + arr[i];
      }
      int ptr1, ptr2, cnt = 0;
      for (int i = 1; i <= N; i++) {
         int cur = arr[i];
         ptr1 = N - 2; ptr2 = N;
         if (ptr1 < 0)continue;
         while (1) {
            if (ptr1 == -1 || psum[ptr2] - psum[ptr1] == cur)break;
            if (ptr1 == ptr2 - 2) {
               ptr1--;
               continue;
            }
            int ded = psum[ptr2] - psum[ptr1];
            if (ded < cur) {
               ptr1--;
               continue;
            }
            if (ded > cur) {
               ptr2--;
               continue;
            }
         }
         if (psum[ptr2] - psum[ptr1] == cur)cnt++;
      }
      cout << cnt << '\n';
   }
}
