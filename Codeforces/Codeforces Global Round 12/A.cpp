#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long N; cin >> N;
		string str; cin >> str;
		map<char, int>m;
		for (char i : str)m[i]++;
		for (int i = 0; i < 26; i++) {
			while (m[i + 'a'] > 0) {
				m[i + 'a']--;
				cout << (char)(i + 'a');
			}
		}cout << '\n';
	}
}
