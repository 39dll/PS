#include <iostream>
#include <string>
using namespace std;
string str; int cnt = 1;
int main() {
	getline(cin, str);
	for (int i = 1; i < str.length() - 1; i++) {
		if (str[i] == ' ') cnt++;
	}
	if (str == " ") {
		cout << 0;
		return 0;
	}
	cout << cnt;
}