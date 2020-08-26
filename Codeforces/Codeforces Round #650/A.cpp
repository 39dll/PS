#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) {
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (i % 2 == 0)cout << str[i];
			if (i % 2 == 1 && i == str.length() - 1)cout << str[i];
		}
		cout << '\n';
	}
}
