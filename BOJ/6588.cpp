#include <iostream>
using namespace std;
int n, T;
bool arr[1001001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 1001000; i++) arr[i] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (arr[i] != 0) {
			for (int j = 2; j <= 1001000 / i; j++) {
				arr[i*j] = 0;
			}
		}
	}
	arr[1] = 0; arr[2] = 1; arr[3] = 1;
	cin >> T;
	while (T) {
		for (int i = 0; i <= T/2; i++) {
			if (arr[i] == 1 && arr[T - i] == 1) {
				cout << T << " = " << i << " + " << T - i << "\n"; break;
			}
			if (i == T/2) cout << "Goldbach's conjecture is wrong\n";
		}
		cin >> T;
	}
	return 0;
}