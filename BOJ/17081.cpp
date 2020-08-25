#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef pair<int, int> p;
//x좌표, y좌표

typedef tuple<string, int, int, int, int, bool> t;
/*
몬스터의 이름, 공격력, 방어력,
최대 체력, 경험치, 보스인지 여부
*/

typedef pair<char, string> p2;
//아이템 타입, 정보

map<p, t> monster;
map<p, p2> item;
map<string, bool> equipped;

int N, M, turn;
char board[103][103], in[103];
string command;
int monscnt, itemcnt;

int plx, ply, fx, fy;
int lv = 1, hp = 20, mxhp = 20, att = 2, def = 2, curexp, reqexp = 5;
int addatt, adddef;

void input();
void pr(int id, string who);
void move(char com);
void battle(int x, int y);

void input() {
	cin >> N >> M;
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			board[i][j] = '#';
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> in;
		for (int j = 1; j <= M; j++) {
			board[i][j] = in[j - 1];
			if (board[i][j] == '@') {
				plx = fx = i;
				ply = fy = j;
				board[i][j] = '.';
			}
			if (board[i][j] == '&' || board[i][j] == 'M')monscnt++;
			if (board[i][j] == 'B')itemcnt++;
		}
	}

	cin >> command;

	for (int i = 0; i < monscnt; i++) {
		int in1, in2, in4, in5, in6, in7;
		string in3;
		cin >> in1 >> in2 >> in3 >> in4 >> in5 >> in6 >> in7;
		if (board[in1][in2] == 'M')monster[{in1, in2}] = { in3,in4,in5,in6,in7,1 };
		else monster[{in1, in2}] = { in3,in4,in5,in6,in7,0 };
	}
	for (int i = 0; i < itemcnt; i++) {
		int in1, in2;
		char in3;
		string in4;
		cin >> in1 >> in2 >> in3 >> in4;
		item[{in1, in2}] = { in3,in4 };
	}
}

void move(char com) {
	turn++;
	int curx = plx, cury = ply, nx, ny;
	if (com == 'L') {
		nx = curx;
		ny = cury - 1;
	}
	if (com == 'R') {
		nx = curx;
		ny = cury + 1;
	}
	if (com == 'U') {
		nx = curx - 1;
		ny = cury;
	}
	if (com == 'D') {
		nx = curx + 1;
		ny = cury;
	}

	if (board[nx][ny] == '.') {
		plx = nx;
		ply = ny;
	}
	if (board[nx][ny] == '^') {
		plx = nx;
		ply = ny;
		if (equipped["DX"])hp--;
		else hp -= 5;
		if (hp <= 0) {
			if (equipped["RE"]) {
				hp = mxhp;
				plx = fx;
				ply = fy;
				equipped["RE"] = 0;
				return;
			}
			pr(0, "SPIKE TRAP");
		}
	}
	if (board[nx][ny] == '#') {
		if (board[curx][cury] == '^') {
			if (equipped["DX"])hp--;
			else hp -= 5;
			if (hp <= 0) {
				if (equipped["RE"]) {
					hp = mxhp;
					plx = fx;
					ply = fy;
					equipped["RE"] = 0;
					return;
				}
				pr(0, "SPIKE TRAP");
			}
		}
	}
	if (board[nx][ny] == 'B') {
		char type = item[{nx, ny}].first;
		string id = item[{nx, ny}].second;
		switch (type) {
		case 'W':
			addatt = stoi(id);
			break;
		case 'A':
			adddef = stoi(id);
			break;
		case 'O':
			int acccnt = 0;
			for (auto i : equipped) {
				if (i.second == 1)acccnt++;
			}
			if (acccnt >= 4)break;
			if (equipped[id])break;
			equipped[id] = 1;
			break;
		}
		board[nx][ny] = '.';
		plx = nx;
		ply = ny;
	}
	if (board[nx][ny] == '&' || board[nx][ny] == 'M') {
		battle(nx, ny);
	}
}

void battle(int x, int y) {
	string name = get<0>(monster[{x, y}]);
	int monatt = get<1>(monster[{x, y}]);
	int mondef = get<2>(monster[{x, y}]);
	int monmxhp = get<3>(monster[{x, y}]);
	int monexp = get<4>(monster[{x, y}]);
	bool isboss = get<5>(monster[{x, y}]);
	int monhp = monmxhp;

	bool firstbonus = equipped["CO"];
	bool firstbossdef = equipped["HU"];

	int playerdamage = max(1, att + addatt - mondef);
	int monsterdamage = max(1, monatt - def - adddef);

	if (isboss) {
		if (firstbossdef)hp = mxhp;
		while (1) {
			if (firstbonus) {
				if (equipped["DX"])monhp -= max(1, (att + addatt) * 3 - mondef);
				else monhp -= max(1, (att + addatt) * 2 - mondef);
				firstbonus = 0;
			}
			else monhp -= playerdamage;
			if (monhp <= 0)break;
			if (firstbossdef) {
				firstbossdef = 0;
				continue;
			}
			hp -= monsterdamage;
			if (hp <= 0) {
				if (equipped["RE"]) {
					hp = mxhp;
					plx = fx;
					ply = fy;
					equipped["RE"] = 0;
					return;
				}
				pr(0, name);
			}
		}
	}
	else {
		while (1) {
			if (firstbonus) {
				if (equipped["DX"])monhp -= max(1, (att + addatt) * 3 - mondef);
				else monhp -= max(1, (att + addatt) * 2 - mondef);
				firstbonus = 0;
			}
			else {
				monhp -= playerdamage;
			}
			if (monhp <= 0)break;
			hp -= monsterdamage;
			if (hp <= 0) {
				if (equipped["RE"]) {
					hp = mxhp;
					plx = fx;
					ply = fy;
					equipped["RE"] = 0;
					return;
				}
				pr(0, name);
			}
		}
	}
	if (equipped["HR"])hp = min(hp + 3, mxhp);
	if (equipped["EX"])curexp += floor(1.2000000000000001 * monexp);
	else curexp += monexp;
	if (curexp >= reqexp) {
		lv++;
		curexp = 0;
		reqexp = 5 * lv;
		mxhp += 5;
		att += 2;
		def += 2;
		hp = mxhp;
	}
	board[x][y] = '.';
	plx = x;
	ply = y;
	if (isboss)pr(1, "");
}

void pr(int id, string who) {
	/*
	id
	0 : killed by who
	1 : Win
	2 : Press any key
	*/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (plx == i && ply == j && id != 0) {
				cout << '@';
				continue;
			}
			cout << board[i][j];
		}
		cout << '\n';
	}
	cout << "Passed Turns : " << turn << '\n';
	cout << "LV : " << lv << '\n';
	cout << "HP : " << max(hp, 0) << '/' << mxhp << '\n';
	cout << "ATT : " << att << '+' << addatt << '\n';
	cout << "DEF : " << def << '+' << adddef << '\n';
	cout << "EXP : " << curexp << '/' << reqexp << '\n';
	if (id == 0)cout << "YOU HAVE BEEN KILLED BY " << who << "..\n";
	if (id == 1)cout << "YOU WIN!\n";
	if (id == 2)cout << "Press any key to continue.\n";
	exit(0);
}

int main() {
	input();
	for (int i = 0; i < command.length(); i++)move(command[i]);
	pr(2, "");
}