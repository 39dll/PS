#include <iostream>
using namespace std;
int calc(int a) {
	return a % 10 + a % 100 / 10 + a % 1000 / 100 + a % 10000 / 1000 + a % 100000 / 10000 + a / 100000 + a;
}
int main() {
	int N;
	cin >> N;
	for (int i = N - 55; i <= N; i++) {
		if (i >= 1) {
			if (calc(i) == N) { cout << i; break; }
			if (i == N) cout << 0;
		}
	}
	return 0;
}