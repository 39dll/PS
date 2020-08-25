#include <iostream>
using namespace std;
int max(int a, int b) {
	if (a > b) return a; else return b;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int N, M = 0, a, b, cnt = 0, A[1001] = { 0, }, B[1001] = { 0, }, c[1001] = { 0, };
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		A[a] = b;
	}
	for (int i = 1; i <= 1000; i++) {
		if (A[i] != 0) {
			cnt++;
			B[cnt] = A[i];
		}
	}
	for (int i = 1; i <= cnt; i++) {
		if (c[i] == 0) c[i] = 1;
		for (int j = 1; j <= cnt; j++) {
			if (B[i] > B[j]){
				if (c[i] < c[j] + 1) {
					c[i] = c[j] + 1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		M = max(M, c[i]);
	}
	cout << cnt - M;
	return 0;
}