#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		string str;
		cin >> str;
		int len = str.length();
		int cur = 0;
		int psum[1001] = { 0 };
		for (int i = 0; i < len; i++) {
			psum[i + 1] = psum[i] + (str[i] == '1');
		}
		int ans = 2100000000;
		for (int i = 0; i <= len; i++) {
			int sum1 = psum[i];
			int sum2 = psum[len] - psum[i];
			ans = min({ ans, i - sum1 + sum2, sum1 + len - i - sum2 });
		}
		cout << ans << '\n';
	}
}
