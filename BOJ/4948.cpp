#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int N, count = 0;
	bool arr[300500];
	for (int i = 1; i <= 300499; i++) arr[i] = 1;
	for (int i = 2; i <= 550; i++) {
		for (int j = 2; j <= 300499 / i; j++) {
			arr[i*j] = 0;
		}
	}
	arr[1] = 0; arr[2] = 1; arr[3] = 1;

	cin >> N;
	while(N){
		for (int i = N + 1; i <= 2 * N; i++) {
			if (arr[i] == 1) {
				count++;
			}
		}
		cout << count << "\n";
		count = 0;
		cin >> N;
	}

	return 0;
}