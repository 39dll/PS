#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int M, N;
	bool arr[1001002];
	for (int i = 1; i <= 1001001; i++) arr[i] = 1;
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; j <= 1001000 / i; j++) {
			arr[i*j] = 0;
		}
	}
	arr[1] = 0; arr[2] = 1; arr[3] = 1;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (arr[i] == 1) {
			cout << i << "\n";
		}
	}

	return 0;
}