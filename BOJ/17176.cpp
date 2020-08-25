#include <iostream>
#include <string>
#include <map>
using namespace std;
int N;
map<char, int> m;
string str;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int in;
		cin >> in;
		if (in == 0) {
			m[' ']++;
		}
		else if (in <= 26) {
			m[in + 'A' - 1]++;
		}
		else {
			m[in + 'a' - 27]++;
		}
	}
	cin.ignore();
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (m[str[i]] <= 0) {
			cout << 'n';
			return 0;
		}
		else {
			m[str[i]]--;
		}
	}
	cout << 'y';
}