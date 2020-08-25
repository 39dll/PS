#include <iostream>
using namespace std;
int min(int a, int b) {
	if (a < b) return a; else return b;
}
int main() {
	int N, P[1001][3], m[1001][3];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 2; j++) {
			cin >> P[i][j];
		}
	}
	m[1][0] = P[1][0]; m[1][1] = P[1][1]; m[1][2] = P[1][2];
	for (int i = 2; i <= N; i++) {
		m[i][0] = min(m[i - 1][1], m[i - 1][2]) + P[i][0];
		m[i][1] = min(m[i - 1][0], m[i - 1][2]) + P[i][1];
		m[i][2] = min(m[i - 1][0], m[i - 1][1]) + P[i][2];
	}
	cout << min(m[N][0], min(m[N][1], m[N][2]));
	return 0;
}