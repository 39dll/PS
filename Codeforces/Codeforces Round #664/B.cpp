#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
bool visit[101][101];
bool dir = 1;
int N, M, r, c;
int vcount;
void p() {
	cout << r << " " << c << "\n";
}
void move(int x, int y) {
	r = x;
	c = y;
	if (!visit[r][c]) p();
	visit[r][c] = true;
}
void t() {
	move(1, c);
	move(r, 1);
}
int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> N >> M >> r >> c;
	p();
	visit[r][c] = 1;
	t();
	while (1) {
		if (dir) {
			if (c + 1 <= M) move(r, c + 1);
			else {
				dir = 0;
				if (r + 1 <= N) move(r + 1, c);
				else break;
			}
		}
		else {
			if (c - 1 > 0) move(r, c - 1);
			else {
				dir = 1;
				if (r + 1 <= N) move(r + 1, c);
				else break;
			}
		}
	}
}
