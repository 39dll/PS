#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int N;
		string str;
		cin >> N >> str;
		bool pos = 0;
		if (str.substr(0, 4) == "2020")pos = 1;
		if (str.substr(0, 3) == "202"&&str[N - 1] == '0')pos = 1;
		if (str.substr(0, 2) == "20"&&str[N - 1] == '0'&&str[N - 2] == '2')pos = 1;
		if (str.substr(0, 1) == "2"&&str[N - 1] == '0'&&str[N - 2] == '2'&&str[N - 3] == '0')pos = 1;
		if (str.substr(N - 4, 4) == "2020")pos = 1;
		cout << (pos ? "YES\n" : "NO\n");
	}
}
