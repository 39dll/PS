#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int T, R;
	char S[21];
	cin >> T;
	while (T--) {
		cin >> R >> S;
		for (int i = 0; S[i] != NULL; i++) {
			for (int j = 1; j <= R; j++) {
				cout << S[i];
			}
		}
		cout << "\n";
	}
}