#include <bits/stdc++.h>
using namespace std;
string str;
int n, k;
map<char, int> m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		m.clear();
		cin >> n >> k >> str;
		int ans = 0, mx = 0, lol = 0;
		for (int i = 0; i < n; i++) {
			m[str[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			int o = 0;
			for (auto j : m) {
				o += j.second / i;
			}
			if (o >= k)ans = max(ans, i*k);
			else for (int j = 1; j <= o; j++) {
				if (k%j == 0)ans = max(ans, i*j);
			}
		}
		cout << ans << '\n';
	}
}
