#include <bits/stdc++.h>
using namespace std;
string str, newstr;
int N;
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> str;
		newstr.clear();
		bool found1 = 0, init = 0, only0 = 1;
		int twostreak = 0;
		for (int i = 0; i < N; i++) {
			if (str[i] == '0') {
				if (i == N - 1) {
					if (only0 == 1) {
						newstr.push_back('0');
						continue;
					}
					else {
						newstr.push_back('2');
						continue;
					}
				}
				if (found1 == 0) {
					newstr.push_back('0');
					continue;
				}
				else {
					
					init = 1;
					continue;
				}
			}
			if (str[i] == '1') {
				only0 = 0;
				if (found1 == 0) {
					found1 = 1;
					init = 0;
					continue;
				}
				if (init == 0)continue;
				if (init == 1) {
					init = 0;
					newstr.push_back('2');
					twostreak++;
					continue;
				}
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			if (str[i] == '1')newstr.push_back('1');
			else break;
		}
		if (newstr[newstr.length() - 1] != '1') {

		}
		if (newstr == "") {
			newstr = "2";
			twostreak = 1;
		}
		int newlen = newstr.length();
		for (int i = 0; i < newlen; i++) {
			if (newstr[i] == '0') {
				cout << '0';
			}
		}
		for (int i = 0; i < newlen; i++) {
			if (newstr[i] == '2') {
				cout << '0';
				break;
			}
		}
		for (int i = 0; i < newlen; i++) {
			if (newstr[i] == '1') {
				cout << '1';
			}
		}
		cout << '\n';
	}
}
