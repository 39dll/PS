#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int n, T;
	bool arr[10101];
	for (int i = 1; i <= 10100; i++) arr[i] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j <= 10100 / i; j++) {
			arr[i*j] = 0;
		}
	}
	arr[1] = 0; arr[2] = 1; arr[3] = 1;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = n / 2; i >= 2; i--) {
			if (arr[i] == 1 && arr[n - i] == 1) {
				cout << i << " " << n - i << "\n"; break;
			}
		}
	}
	return 0;
}