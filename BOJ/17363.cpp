#include <iostream>
using namespace std;
char c[102][102], c2[102][102];
int N, M;
char trans(char a) {
	switch (a) {
	case '.': return '.';
	case 'O': return 'O';
	case '-': return '|';
	case '|': return '-';
	case '/': return '\\';
	case '\\': return '/';
	case '^': return '<';
	case '<': return 'v';
	case 'v': return '>';
	case '>': return '^';
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			c2[j][i] = trans(c[i][j]);
		}
	}
	for (int j = M - 1; j >= 0; j--) {
		for (int i = 0; i < N; i++) {
			cout << c2[j][i];
		}
		cout << "\n";
	}
}