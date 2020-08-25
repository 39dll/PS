#include <iostream>
using namespace std;
int q[10001], a[10001][2], n;
int max(int a, int b) {
	if (a > b) return a; else return b;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> q[i];
	}
	a[1][0] = q[1]; a[1][1] = 0;
	a[2][0] = q[2]; a[2][1] = q[1] + q[2];
	a[3][0] = q[1] + q[3]; a[3][1] = q[2] + q[3];
	for (int i = 4; i <= n; i++) {
		a[i][1] = a[i - 1][0] + q[i];
		a[i][0] = max(max(a[i - 2][0], a[i - 2][1]), max(a[i - 3][0], a[i - 3][1])) + q[i];
	}
	cout << max(max(a[n][0], a[n][1]),max(a[n-1][0],a[n-1][1]));
}