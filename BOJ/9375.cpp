#include <iostream>
#include <utility>
#include <string>
using namespace std;
int T, N;
string type[31], a, b;
int quantity[31] = { 0, }, ans = 1;
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			type[i] = "";
			quantity[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			cin >> a >> b;
			for (int j = 1; j <= i; j++) {
				if (type[j] == b) { quantity[j]++; break; }
				if (j == i) { type[j] = b; quantity[j]++; }
			}
		}
		for (int i = 1; i <= N; i++) {
			ans *= quantity[i] + 1;
		}
		cout << ans - 1 << "\n";
		ans = 1;
	}
	return 0;
}