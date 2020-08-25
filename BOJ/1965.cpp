#include <iostream>
#include <algorithm>
using namespace std;
int N, M, A[1001], c[1001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
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
	for (int i = 1; i <= N; i++) {
		M = max(M, c[i]);
	}
	cout << M;
	return 0;
}