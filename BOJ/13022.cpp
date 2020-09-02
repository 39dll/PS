#include <iostream>
#include <string>
using namespace std;
string str;
int cnt[4];
int main() {
	cin >> str;
	if (str[str.length() - 1] != 'f') {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'w') {
			if (cnt[1] || cnt[2] || cnt[3]) {
				if (cnt[0] == cnt[1] && cnt[2] == cnt[3] && cnt[0] == cnt[2]) {
					cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
					cnt[0]++;
					continue;
				}
				else {
					cout << 0;
					return 0;
				}
			}
			else {
				cnt[0]++;
			}
		}
		if (str[i] == 'o') {
			if (cnt[2] != 0 || cnt[3] != 0) {
				cout << 0;
				return 0;
			}
			cnt[1]++;
		}
		if (str[i] == 'l') {
			if (cnt[3] != 0) {
				cout << 0;
				return 0;
			}
			if (cnt[0] != cnt[1]) {
				cout << 0;
				return 0;
			}
			cnt[2]++;
		}
		if (str[i] == 'f') {
			if (cnt[0] != cnt[1] || cnt[1] != cnt[2] || cnt[0] != cnt[2]) {
				cout << 0;
				return 0;
			}
			cnt[3]++;
		}
		if (i == str.length() - 1) {
			if (cnt[0] == cnt[1] && cnt[2] == cnt[3] && cnt[0] == cnt[2]) {
				cout << 1;
				return 0;
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}
}