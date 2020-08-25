#include <iostream>
using namespace std;
int max(int a, int b) {
	if (a > b) return a; else return b;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int N, M = 0, A[1001] = { 0, }, c[1001] = { 0, }, c2[1001] = { 0, };
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		if (c[i] == 0) c[i] = 1;
		for (int j = 1; j <= N; j++) {
			if (A[i] > A[j]) {
				if (c[i] < c[j] + 1) {
					c[i] = c[j] + 1;
				}
			}
		}
	}
	for (int i = N; i >= 1; i--) {
		if (c2[i] == 0) c2[i] = 1;
		for (int j = N; j >= 1; j--) {
			if (A[i] > A[j]) {
				if (c2[i] < c2[j] + 1) {
					c2[i] = c2[j] + 1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		M = max(M, c[i] + c2[i] - 1);
	}
	cout << M;
	return 0;
}