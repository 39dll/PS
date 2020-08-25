#include <iostream>
using namespace std;
int N;
long long a[101][10];
long long ans;
int main() {
	a[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		a[1][i] = 1;
	}
	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j <= 8; j++) {
			a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) % 1000000000;
		}
		a[i][0] = a[i - 1][1];
		a[i][9] = a[i - 1][8];
	}
	cin >> N;
	ans = a[N][0] + a[N][1] + a[N][2] + a[N][3] + a[N][4] + a[N][5] + a[N][6] + a[N][7] + a[N][8] + a[N][9];
	cout << ans % 1000000000;
}