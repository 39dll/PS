#include <stack>
#include <iostream>
using namespace std;
int main() {
	int T, counter = 0;
	char temp[51];
	stack<char> a;
	cin >> T;
	while (T--) {
		cin >> temp;
		for (int i = 0; temp[i] == '(' || temp[i] == ')'; i++) {
			a.push(temp[i]);
		}
		for (int i = a.size(); i >= 1; i--) {
			if (a.top() == ')') {
				counter++;
				a.pop();
			}
			else if (a.top() == '(') {
				counter--;
				a.pop();
			}
			if (counter < 0) break;
		}
		if (counter == 0) cout << "YES\n";
		else cout << "NO\n";
		counter = 0;
		while (!a.empty()){ a.pop(); }
	}
	return 0;
}