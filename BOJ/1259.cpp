#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string str, str2;
	cin >> str;
	while (str != "0") {
		str2 = str;
		reverse(str2.begin(), str2.end());
		if (str == str2) cout << "yes\n";
		else cout << "no\n";
		cin >> str;
	}
}