#include <bits/stdc++.h>
using namespace std;
typedef pair<int, double> pid;
int main() {
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int T; cin >> T;
   while (T--) {
      int n, q, tl = -1; cin >> n >> q;
      vector<int> perm(n); for (auto& i : perm) cin >> i;
      vector<pid> query;
      for (int i = n - 1, cnt = 0; i >= 0; i--, cnt++) {
         if (perm[i] != n - cnt) {
            tl = n - cnt; break;
         }
      }
      for (int i = 0; i < q; i++) {
         int rg; double pr; cin >> rg >> pr;
         if (rg < tl) continue;
         query.push_back({ rg, pr });
      }
      sort(query.begin(), query.end());
      double res = 1;
      for (int i = query.size() - 1; i >= 0; i--) {
         res *= (1 - query[i].second);
      }

      if (tl == -1) {
         cout << 1 << '\n'; continue;
      }
      cout << 1.0 - res << '\n';
   }
}
