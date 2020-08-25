#include <iostream>
#include <string>
#include <stack>
using namespace std;
string str;
stack<char> bracket;
bool ok = 1;
int main() {
	while (1) {
		getline(cin, str);
		if (str == ".") break;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				bracket.push(str[i]);
			}
			else {
				if (str[i] == ')') {
					if (!bracket.empty() && bracket.top() == '(') {
						bracket.pop();
					}
					else {
					ok = 0; 
					break;
					}
				}
				if (str[i] == ']') {
					if (!bracket.empty() && bracket.top() == '[') {
						bracket.pop();
					}
					else {
						ok = 0;
						break;
					}
				}
			}
		}
		if (ok == 1 && bracket.empty()) cout << "yes\n";
		else cout << "no\n";
		ok = 1;
		str.clear();
		while (!bracket.empty()) bracket.pop();
	}
	return 0;
}