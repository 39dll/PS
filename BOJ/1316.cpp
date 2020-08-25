#include <iostream>
#include <string>
using namespace std;
int N, cnt = 0;
string str;
bool isShown[26] = { 0, };
int main() {
	cin >> N;
	while (N--) {
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (i == 0) {
				isShown[str[i] - 'a'] = 1;
			}
			else {
				if (str[i] == str[i - 1]) {
					if (i != str.length() - 1) continue;
					else {
						cnt++; break;
					}
				}
				else {
					if (isShown[str[i] - 'a']) break;
					else isShown[str[i] - 'a'] = 1;
				}
			}
			if (i == str.length() - 1) cnt++;
		}
		for (int i = 0; i < 26; i++) isShown[i] = 0;
		str.clear();
	}
	cout << cnt;
}