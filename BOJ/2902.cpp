#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
stack<char> s;
string str, str2;
int main() {
	cin >> str;
	for (int i = str.length() - 1; i >= 0; i--) {
		s.push(str[i]);
		if (s.top() == '-') {
			s.pop();
			str2 += s.top();
		}
	}
	str2 += str[0];
	reverse(str2.begin(), str2.end());
	cout << str2;
}