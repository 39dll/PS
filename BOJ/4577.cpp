#include <iostream>
#include <cstring>
using namespace std;
int plx, ply, N, M, cnt = 1;
char mp[17][17], in[17], com[52];
bool comp;
void move(char com) {
	int curx, cury, nx, ny, nnx, nny;
	curx = plx; cury = ply;
	if (com == 'L') {
		nx = plx; ny = ply - 1;
		nnx = plx; nny = ply - 2;
	}
	if (com == 'R') {
		nx = plx; ny = ply + 1;
		nnx = plx; nny = ply + 2;
	}
	if (com == 'U') {
		nx = plx - 1; ny = ply;
		nnx = plx - 2; nny = ply;
	}
	if (com == 'D') {
		nx = plx + 1; ny = ply;
		nnx = plx + 2; nny = ply;
	}
	char cur = mp[curx][cury], nt = mp[nx][ny], ntnt = mp[nnx][nny];
	if (nt == '#')return; //벽이 있을 때
	if (nt == '.' || nt == '+') { //빈 칸일 때
		if (cur == 'w')mp[curx][cury] = '.';
		if (cur == 'W')mp[curx][cury] = '+';
		if (nt == '.')mp[nx][ny] = 'w';
		if (nt == '+')mp[nx][ny] = 'W';
		plx = nx; ply = ny;
	}
	if (nt == 'b' || nt == 'B') {//블록이 있을 때
		if (ntnt == '#' || ntnt == 'b' || ntnt == 'B')return;
		if (ntnt == '.' || ntnt == '+') {
			if (ntnt == '.')mp[nnx][nny] = 'b';
			if (ntnt == '+')mp[nnx][nny] = 'B';
			if (nt == 'b')mp[nx][ny] = 'w';
			if (nt == 'B')mp[nx][ny] = 'W';
			if (cur == 'w')mp[curx][cury] = '.';
			if (cur == 'W')mp[curx][cury] = '+';
		}
		plx = nx; ply = ny;
	}
}
bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mp[i][j] == 'b')return 0;
		}
	}
	comp = 1;
	return 1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		comp = 0;
		cin >> N >> M;
		if (N == 0)break;
		for (int i = 0; i < N; i++) {
			cin >> in;
			for (int j = 0; j < M; j++) {
				mp[i][j] = in[j];
				if (mp[i][j] == 'w' || mp[i][j] == 'W') {
					plx = i; ply = j;
				}
			}
		}
		cin >> com;
		for (int i = 0; i < strlen(com); i++) {
			if (comp == 1)break;
			move(com[i]);
			check();
		}
		cout << "Game " << cnt << ": "; cnt++;
		if (comp == 0) cout << "in";
		cout << "complete\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << mp[i][j];
			}
			cout << '\n';
		}
	}
}