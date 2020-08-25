#include <iostream>
using namespace std;
int T, N;
char ch[9];
long long a[9];
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> a[0] >> ch[1] >> a[2] >> ch[3] >> a[4];
		if (ch[1] == '*') {
			if (a[4] == a[2] * a[0]) {
				cout << "correct\n";
			}
			else cout << "wrong answer\n";
			continue;
		}
		else if (ch[1] == '+') {
			if (a[4] == a[2] + a[0]) {
				cout << "correct\n";
			}
			else cout << "wrong answer\n";
			continue;
		}
		else if (ch[1] == '-') {
			if (a[4] == a[0] - a[2]) {
				cout << "correct\n";
			}
			else cout << "wrong answer\n";
			continue;
		}
		else if (ch[1] == '/') {
			if (a[4] == a[0] / a[2]) {
				cout << "correct\n";
			}
			else cout << "wrong answer\n";
			continue;
		}
	}
}