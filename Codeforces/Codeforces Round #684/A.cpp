#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {

		long long n, c0, c1, h;
		string s;
		cin >> n >> c0 >> c1 >> h;
		cin >> s;
		long long cost = 0;
		if (c0 >= c1) {
			if (h < c0 - c1) {
				for (int i = 0; i < n; i++) {
					if (s[i] == '0') {
						cost += h;
						s[i] = '1';
					}
				}
			}
		}
		if (c0 < c1) {
			if (h < c1 - c0) {
				for (int i = 0; i < n; i++) {
					if (s[i] == '1') {
						cost += h;
						s[i] = '0';
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (s[i] == '0')cost += c0;
			else cost += c1;
		}
		cout << cost << '\n';
	}
}
