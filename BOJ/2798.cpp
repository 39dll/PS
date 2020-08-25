#include <iostream>
using namespace std;
int main() {
	int N, M, sum = 0;
	cin >> N >> M;
	int *a = new int[N];
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (a[i] + a[j] + a[k] <= M && a[i] + a[j] + a[k] > sum) {
					sum = a[i] + a[j] + a[k];
				}
			}
		}
	}
	cout << sum;
	return 0;
}