#include <iostream>
#include <string>
using namespace std;
int N;
char msg[24][24];
string name[24];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	int grp = 1;
	while (N != 0) {
		char in2;
		bool nasty = 0;
		for (int i = 1; i <= N; i++) {
			cin >> name[i];
			for (int j = 1; j < N; j++) {
				cin >> msg[i][j];
				if (msg[i][j] == 'N')nasty = 1;
			}
		}
		if (nasty == 0) {
			cout << "Group " << grp << '\n';
			cout << "Nobody was nasty\n\n";
		}
		else {
			cout << "Group " << grp << '\n';
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j < N; j++) {
					if (msg[i][j] == 'N') {
						if (i - j >= 1) {
							cout << name[i - j] << " was nasty about " << name[i] << '\n';
						}
						else {
							cout << name[i - j + N] << " was nasty about " << name[i] << '\n';
						}
					}
				}
			}
			cout << '\n';
		}
		grp++;
		cin >> N;
	}
}