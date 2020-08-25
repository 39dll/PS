#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> p;
queue<p> q;
int stx, sty, endx, endy, nstx, nsty, nendx, nendy;
char in[4][8][4], in2[4][4];
bool l[7][7], r[7][7], u[7][7], d[7][7];
bool nl[7][7], nr[7][7], nu[7][7], nd[7][7];
bool nbl, nbr, nbu, nbd, nnbl, nnbr, nnbu, nnbd;
bool visited[7][7];
void init(int k) {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			nl[i][j] = l[i][j];
			nr[i][j] = r[i][j];
			nu[i][j] = u[i][j];
			nd[i][j] = d[i][j];
		}
	}
	nstx = stx;
	nsty = sty;
	nendx = endx;
	nendy = endy;
	if (k == 0) {
		nnbl = nbl;
		nnbu = nbu;
		nnbr = nbr;
		nnbd = nbd;
	}
	if (k == 1) {
		nnbl = nbu;
		nnbu = nbr;
		nnbr = nbd;
		nnbd = nbl;
	}
	if (k == 2) {
		nnbl = nbr;
		nnbu = nbd;
		nnbr = nbl;
		nnbd = nbu;
	}
	if (k == 3) {
		nnbl = nbd;
		nnbu = nbl;
		nnbr = nbu;
		nnbd = nbr;
	}
}
void input() {
	for (int t = 0; t < 7; t++) {
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 7; k++) {
				cin >> in[i][k];
			}
		}
		for (int k = 0; k < 7; k++) {
			l[t][k] = in[1][k][0] == '-';
			r[t][k] = in[1][k][2] == '-';
			u[t][k] = in[0][k][1] == '|';
			d[t][k] = in[2][k][1] == '|';
		}
	}
	for (int i = 0; i < 3; i++) {
		cin >> in2[i];
	}
	nbl = in2[1][0] == '-';
	nbr = in2[1][2] == '-';
	nbu = in2[0][1] == '|';
	nbd = in2[2][1] == '|';
}
bool solve() {
	for (int a = 1; a < 7; a += 2) {
		for (int c = 0; c < 4; c++) {//left, right, up, down
			for (int k = 0; k < 4; k++) {
				while (!q.empty())q.pop();
				init(k);
				if (c == 0) {
					for (int i = 5; i >= 0; i--) {
						nr[a][i + 1] = nr[a][i];
						nl[a][i + 1] = nl[a][i];
						nu[a][i + 1] = nu[a][i];
						nd[a][i + 1] = nd[a][i];
					}
					nr[a][0] = nnbr; nl[a][0] = nnbl; nu[a][0] = nnbu; nd[a][0] = nnbd;

					if (nstx == a) {
						if (nsty == 6) {
							nsty = 0;
						}
						else nsty++;
					}
					if (nendx == a) {
						if (nendy == 6) {
							continue;
						}
						else nendy++;
					}
				}
				if (c == 1) {
					for (int i = 1; i < 7; i++) {
						nr[a][i - 1] = nr[a][i];
						nl[a][i - 1] = nl[a][i];
						nu[a][i - 1] = nu[a][i];
						nd[a][i - 1] = nd[a][i];
					}
					nr[a][6] = nnbr; nl[a][6] = nnbl; nu[a][6] = nnbu; nd[a][6] = nnbd;

					if (nstx == a) {
						if (nsty == 0) {
							nsty = 6;
						}
						else nsty--;
					}
					if (nendx == a) {
						if (nendy == 0) {
							continue;
						}
						else nendy--;
					}
				}
				if (c == 2) {
					for (int i = 5; i >= 0; i--) {
						nr[i + 1][a] = nr[i][a];
						nl[i + 1][a] = nl[i][a];
						nu[i + 1][a] = nu[i][a];
						nd[i + 1][a] = nd[i][a];
					}
					nr[0][a] = nnbr; nl[0][a] = nnbl; nu[0][a] = nnbu; nd[0][a] = nnbd;

					if (nsty == a) {
						if (nstx == 6) {
							nstx = 0;
						}
						else nstx++;
					}
					if (nendy == a) {
						if (nendx == 6) {
							continue;
						}
						else nendx++;
					}
				}
				if (c == 3) {
					for (int i = 1; i < 7; i++) {
						nr[i - 1][a] = nr[i][a];
						nl[i - 1][a] = nl[i][a];
						nu[i - 1][a] = nu[i][a];
						nd[i - 1][a] = nd[i][a];
					}
					nr[6][a] = nnbr; nl[6][a] = nnbl; nu[6][a] = nnbu; nd[6][a] = nnbd;

					if (nsty == a) {
						if (nstx == 0) {
							nstx = 6;
						}
						else nstx--;
					}
					if (nendy == a) {
						if (nendx == 0) {
							continue;
						}
						else nendx--;
					}
				}
				q.push({ nstx,nsty });
				visited[nstx][nsty] = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					if (x == nendx && y == nendy) {
						return 1;
					}
					//left
					if (y > 0 && visited[x][y - 1] == 0 && nl[x][y] && nr[x][y - 1]) {
						visited[x][y - 1] = 1;
						q.push({ x,y - 1 });
					}
					//right
					if (y < 6 && visited[x][y + 1] == 0 && nr[x][y] && nl[x][y + 1]) {
						visited[x][y + 1] = 1;
						q.push({ x,y + 1 });
					}
					//up
					if (x > 0 && visited[x - 1][y] == 0 && nu[x][y] && nd[x - 1][y]) {
						visited[x - 1][y] = 1;
						q.push({ x - 1,y });
					}
					//down
					if (x < 6 && visited[x + 1][y] == 0 && nd[x][y] && nu[x + 1][y]) {
						visited[x + 1][y] = 1;
						q.push({ x + 1,y });
					}
				}
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> stx >> sty >> endx >> endy;
	while (stx != 0) {
		input();
		stx--; sty--; endx--; endy--;
		if (solve() == 1)cout << "You can win in one move.\n";
		else cout << "Bad luck!\n";
		cin >> stx >> sty >> endx >> endy;
	}
}