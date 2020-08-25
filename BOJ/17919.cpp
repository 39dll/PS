#include <iostream>
#include <string>
using namespace std;
string str;
int ost = 0, total = 0, temp = 0;
int main() {
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (i != 0 && str[i] == 'e' && str[i - 1] == 'a') {
			temp = 1;
		}
		if (str[i] == ' ' || i == str.length() - 1) {
			if (temp == 1) ost++;
			total++;
			temp = 0;
			continue;
		}
	}
	if (10 * ost >= 4 * total) cout << "dae ae ju traeligt va";
	else cout << "haer talar vi rikssvenska";
}