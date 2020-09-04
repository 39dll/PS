#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	int streak = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'P')streak++;
		else {
			if (streak <= 1) {
				cout << "NP";
				return 0;
			}
			if (i == str.length() - 1 || str[i + 1] == 'A') {
				cout << "NP";
				return 0;
			}
			streak -= 2;
		}
	}
	if (streak == 1)cout << "PPAP";
	else cout << "NP";
}