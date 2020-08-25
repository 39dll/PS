#include <iostream>
#include <string>
using namespace std;
int cnt = 0, ctn = 0;
string str;
int main() {
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (ctn == 0) {
			if (i < str.length() - 2) {
				if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') {
					cnt++; ctn = 2; continue;
				}
			}
			if (i < str.length() - 1) {
				if (str[i] == 'c' && str[i + 1] == '=') {
					cnt++; ctn = 1; continue;
				}
				else if (str[i] == 'c' && str[i + 1] == '-') {
					cnt++; ctn = 1; continue;
				}
				else if (str[i] == 'd' && str[i + 1] == '-') {
					cnt++; ctn = 1; continue;
				}
				else if (str[i] == 'l' && str[i + 1] == 'j') {
					cnt++; ctn = 1; continue;
				}
				else if (str[i] == 'n' && str[i + 1] == 'j') {
					cnt++; ctn = 1; continue;
				}
				else if (str[i] == 's' && str[i + 1] == '=') {
					cnt++; ctn = 1; continue;
				}
				else if (str[i] == 'z' && str[i + 1] == '=') {
					cnt++; ctn = 1; continue;
				}
			}
			cnt++;
		}
		else {
			ctn--;
			continue;
		}
	}
	cout << cnt;
}