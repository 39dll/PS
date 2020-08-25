#include <iostream>
using namespace std;
int n[3000002], N;
int min(int a, int b) {
	if (a < b) return a; else return b;
}
int main() {
	cin >> N;
	for (int i = 0; i < 3000002; i++) {
		n[i] = 999999;
	}
	n[N] = 0;
	for (int i = N - 1; i >= 1; i--) {
		n[i] = min(min(n[i * 3], n[i * 2]), n[i + 1]) + 1;
	}
	cout << n[1];
	return 0;
}