#include <iostream>
#include <string>
using namespace std;
int N, M, Bcnt = 0, Wcnt = 0, cnt = 0;
string str, str2;
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> N;
	while (N--) {
		cin >> M >> str >> str2;
		for (int i = 0; i < M; i++) {
			if (str[i] != str2[i]) {
				if (str[i] == 'B') Bcnt++;
				else Wcnt++;
			}
		}
		while (Bcnt != 0 || Wcnt != 0) {
			if (Bcnt > 0 && Wcnt > 0) {
				Bcnt--; Wcnt--; cnt++;
			}
			else if (Bcnt > 0) {
				Bcnt--; cnt++;
			}
			else if (Wcnt > 0) {
				Wcnt--; cnt++;
			}
		}
		cout << cnt << "\n";
		cnt = 0; Bcnt = 0; Wcnt = 0;
	}
}