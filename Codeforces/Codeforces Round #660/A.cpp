#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int T, in;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> in;
		if (in <= 30) {
			cout << "NO\n";
		}
		else {
			if (in != 36 && in != 40 && in != 44) {
				cout << "YES\n6 10 14 " << in - 30 << "\n";
				continue;
			}
			switch(in) {
			case 36:
				cout << "YES\n5 6 10 15\n";
				break;
			case 40:
				cout << "YES\n6 9 10 15\n";
				break;
			case 44:
				cout << "YES\n6 7 10 21\n";
				break;
			}
		}
	}
}
