#include <iostream>
#include <string>
using namespace std;
int T, N;
char ch[1002];
string str;
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> ch[i];
		}
		str += ch[0];
		for (int i = 1; i < N; i++) {
			if (ch[i] <= str[0]) {
				str = ch[i] + str;
			}
			else {
				str.push_back(ch[i]);
			}
		}
		cout << str << "\n";
		str.clear();
	}
}