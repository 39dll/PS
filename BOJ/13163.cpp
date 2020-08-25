#include <iostream>
#include <string>
using namespace std;
int N;
string str, newstr;
bool found;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	cin.ignore(1);
	while (N--) {
		getline(cin, str);
		for (int i = 0; i < str.length(); i++) {
			if (found == 0) {
				if (str[i] == ' ') {
					found = 1;
				}
			}
			else {
				if (str[i] != ' ') {
					newstr += str[i];
				}
			}
		}
		cout << "god" + newstr << "\n";
		str.clear(); newstr.clear(); found = 0;
	}
}