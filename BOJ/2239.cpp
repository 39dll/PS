#include <iostream>
#include <cstdlib>
using namespace std;
int a[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];
char in[12];
void go(int n) {
	int i = n / 9;
	int j = n % 9;
	if (n == 81) {
		for (int n = 0; n < 9; n++) {
			for (int m = 0; m < 9; m++) {
				cout << a[n][m];
			}
			cout << "\n";
		}
		exit(0);
	}
	if (a[i][j] == 0) {
		for (int k = 1; k <= 9; k++) {
			if (row[i][k] == 0 && col[j][k] == 0 && square[(i / 3) * 3 + (j / 3)][k] == 0) {
				row[i][k] = 1;
				col[j][k] = 1;
				square[(i / 3) * 3 + (j / 3)][k] = 1;
				a[i][j] = k;
				go(n + 1);
				a[i][j] = 0;
				row[i][k] = 0;
				col[j][k] = 0;
				square[(i / 3) * 3 + (j / 3)][k] = 0;
			}
		}
	}
	else go(n + 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		cin >> in;
		for (int j = 0; j < 9; j++) {
			a[i][j] = in[j] - '0';
			if (a[i][j] != 0) {
				row[i][a[i][j]] = 1;
				col[j][a[i][j]] = 1;
				square[(i / 3) * 3 + (j / 3)][a[i][j]] = 1;
			}
		}
	}
	go(0);
	return 0;
}