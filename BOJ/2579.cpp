#include <iostream>
using namespace std;
int a[305] = { 0, }, m[305][2] = { { 0, }, }, N, s;
int max(int a, int b) {
	if (a > b) return a; else return b;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[N + 1 - i];
	}
	m[1][0] = a[1]; m[1][1] = -99999;
	m[2][0] = -99999; m[2][1] = m[1][0] + a[2];
	for (int i = 3; i <= N; i++) {
		m[i][0] = max(m[i - 2][0], m[i - 2][1]) + a[i];
		m[i][1] = m[i - 1][0] + a[i];
	}
	cout << max(max(m[N][0], m[N][1]), max(m[N-1][0], m[N-1][1]));
	return 0;
}