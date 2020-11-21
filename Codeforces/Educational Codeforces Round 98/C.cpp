#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		string str;
		cin >> str;
		int a = 0, b = 0, ans = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				a++;
			}
			if (str[i] == ')') {
				if (a >= 1)ans++, a--;
			}
			if (str[i] == '[') {
				b++;
			}
			if (str[i] == ']') {
				if (b >= 1)ans++, b--;
			}
		}
		cout << ans << '\n';
	}
}
