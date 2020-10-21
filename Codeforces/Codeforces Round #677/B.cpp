#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T;
  while(T--) {
		long long n; cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		long long ans = 0;
		long long str = 0;
		bool fs = 1;
		for (int i = 0; i < n; i++) {
			if (v[i] == 0) {
				if (fs == 1)continue;
				str++;
			}
			else {
				if (fs == 1) {
					fs = 0;
				}
				else {
					ans += str;
					str = 0;
				}
			}
		}
		cout << ans << '\n';
	}
}
