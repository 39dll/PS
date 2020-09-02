#include <bits/stdc++.h>
using namespace std;
int N, M, A[5001], c[5001];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)cin >> A[i];
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
	for (int i = 1; i <= N; i++)M = max(M, c[i]);
	cout << M;
	return 0;
}