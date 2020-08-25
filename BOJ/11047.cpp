#include <iostream>
using namespace std;
int main() {
	int N, K, c = 0;
	cin >> N >> K;
	int *a = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		while (K >= a[i]) {
			K -= a[i];
			c++;
		}
	}
	cout << c;
}