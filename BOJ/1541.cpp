#include <iostream>
#include <string>
using namespace std;
int main() {
	bool minus = 0;
	int min = 0;
	string temp = "";
	string s;
	cin >> s;
	for (int i = 0; i <= s.size(); i++){
		if (s[i] == '-' || s[i] == '+' || s[i] == NULL) {
			if (minus == 1) {
				min -= stoi(temp);
				temp = "";
			}
			else {
				min += stoi(temp);
				temp = "";
			}
			if (s[i] == '-' && minus == 0) {
				minus = 1;
			}
		}
		else {
			temp += s[i];
		}
	}
	cout << min;
	return 0;
}