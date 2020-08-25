#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string str, str2;
int main() {
	cin >> str >> str2;
	reverse(str.begin(), str.end());
	reverse(str2.begin(), str2.end());
	if (stoi(str) > stoi(str2)) {
		cout << str;
	}
	else cout << str2;
}