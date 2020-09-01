#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		string ans = "";
		for (int i = 0; i < b; i++) {
			if (ans == "")ans = "0";
			if (ans.back() == '0')ans += '1';
			else ans += '0';
		}
		int pos = -1;
		for (int i = 0; i < ans.length(); i++) {
			if (ans[i] == '0') {
				pos = i;
				break;
			}
		}
		for (int i = 0; i < a; i++) {
			if (ans == "") {
				ans = "0";
				pos = 0;
			}
			ans = ans.substr(0, pos) + '0' + ans.substr(pos, ans.length() - pos);
		}
		pos = -1;
		for (int i = 0; i < ans.length(); i++) {
			if (ans[i] == '1') {
				pos = i;
				break;
			}
		}
		for (int i = 0; i < c; i++) {
			if (ans == "") {
				ans = "1";
				pos = 0;
			}
			ans = ans.substr(0, pos) + '1' + ans.substr(pos, ans.length() - pos);
		}
		cout << ans << '\n';
	}
}
