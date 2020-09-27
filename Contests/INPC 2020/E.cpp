#include<bits/stdc++.h>
using namespace std;
string str, ans;
int N, cap[27];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	getline(cin, str);
	cin >> N;
	for (int i = 0; i < 26; i++)cin >> cap[i];

	char lastchar;
	if (str[0] >= 'A'&&str[0] <= 'Z') {
		lastchar = str[0];
		cap[str[0] - 'A']--;
		ans += lastchar;
	}
	else {
		lastchar = str[0];
		cap[str[0] - 'a']--;
		ans += lastchar;
	}
	for (int i = 1; i < str.length(); i++) {
		if (str[i - 1] != ' ') {
			continue;
		}
		if (str[i] >= 'A'&&str[i] <= 'Z') {
			ans += str[i];
		}
		if (str[i] >= 'a'&&str[i] <= 'z') {
			ans += str[i];
		}
	}
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == ' ') {
			if (str[i - 1] != ' ')N--;
		}
		if (str[i] >= 'A'&&str[i] <= 'Z') {
			if (str[i - 1] == str[i])continue;
			cap[str[i] - 'A']--;
		}
		if (str[i] >= 'a'&&str[i] <= 'z') {
			if (str[i - 1] == str[i])continue;
			cap[str[i] - 'a']--;
		}
	}
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] >= 'a'&&ans[i] <= 'z')ans[i] += 'A' - 'a';
	}

	if (ans[0] >= 'A'&&ans[0] <= 'Z') {
		cap[ans[0] - 'A']--;
	}
	for (int i = 1; i < ans.length(); i++) {
		if (ans[i] != ans[i - 1]) cap[ans[i] - 'A']--;
	}

	for (int i = 0; i < 26; i++) {
		if (cap[i] < 0) {
			cout << -1;
			return 0;
		}
	}
	if (N < 0) {
		cout << -1;
		return 0;
	}
	cout << ans;
}
