#include <iostream>
using namespace std;
char a[3000][3000];
void star(int n, int x, int y) {
	if (n == 1) {
		a[x][y] = '*'; return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			star(n / 3, x + (n / 3 * i), y + (n / 3 * j));
		}
	}
}
int main() {
	int N;
	for (int i = 0; i < 3000; i++) {
		for (int j = 0; j < 3000; j++) {
			a[i][j] = ' ';
		}
	}
	cin >> N;
	star(N, 0, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}