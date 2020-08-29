#include <iostream>
using namespace std;
typedef pair<int, int> p;
int N, M;
p uf[2001][2001];
p find(int x, int y) {
	if (uf[x][y] == make_pair(x, y)) return make_pair(x, y);
	p k = find(uf[x][y].first, uf[x][y].second);
	return uf[x][y] = k;
}
void merge(int x1, int y1, int x2, int y2) {
	p a = find(x1, y1);
	p b = find(x2, y2);
	if (a != b) {
		uf[x2][y2] = a;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			uf[i][j] = { i,j };
		}
	}
}