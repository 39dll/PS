#include <iostream>
#include <algorithm>
using namespace std;
int N, x, y, in, mx;
int X[1001][1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> x >> y; x -= 1; y -= 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> X[i][j];
		}
	}
	mx = X[x][y];
	for (int i = 0; i < N; i++) {
		mx = max(mx, X[i][y]);
		mx = max(mx, X[x][i]);
	}
	if (mx > X[x][y])cout << "ANGRY";
	else cout << "HAPPY";
}