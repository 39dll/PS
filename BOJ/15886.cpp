#include <iostream>
#include <map>
using namespace std;
typedef pair<int, int> p;
char mp[1002][1002];
p par[1002][1002];
map<p, int> m;
int N, M;
p find(int x, int y) {
	if (par[x][y] == make_pair(x, y)) return make_pair(x, y);
	p k = find(par[x][y].first, par[x][y].second);
	par[x][y] = k;
	return k;
}
void merge(int x1, int y1, int x2, int y2) {
	p a = find(x1, y1);
	p b = find(x2, y2);
	if (a != b) {
		par[x2][y2] = a;
	}
}
int main() {
	cin >> M; N = 1;
	for (int i = 0; i < N; i++) {
		cin >> mp[i];
		for (int j = 0; j < M; j++) {
			par[i][j] = { i,j };
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			switch (mp[i][j]) {
			case 'S':
				merge(i + 1, j, i, j);
				break;
			case 'N':
				merge(i - 1, j, i, j);
				break;
			case 'W':
				merge(i, j - 1, i, j);
				break;
			case 'E':
				merge(i, j + 1, i, j);
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			m[find(i, j)]++;
		}
	}
	cout << m.size();
}