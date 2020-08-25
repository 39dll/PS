#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N, loc[4], loc2[4];
char b[34][34];
int gN(string str) {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'F')cnt++;
	}
	if (cnt == 0)return 5;
	else return cnt;
}
int gD(int start, int num) {
	if (start == 1)return 31;
	if (start == 0)return start + num + 1;
	if (start == 6) return 20 + num;
	if (start == 23) {
		if (num <= 2)return 27 + num;
		if (num == 3)return 1;
		return 31;
	}
	if (start >= 21 && start <= 25) {
		if (start + num <= 25)return start + num;
		return start + num - 10;
	}
	if (start == 11) {
		if (num == 3)return 23;
		if (num <= 2) return 25 + num;
		return 24 + num;
	}
	if (start == 26 || start == 27) {
		if (start + num == 27)return 27;
		if (start + num == 28)return 23;
		if (start + num <= 30)return start + num - 1;
		if (start + num > 31)return 31;
		return 1;
	}
	if (start == 28 || start == 29) {
		if (start + num <= 29)return 29;
		if (start + num == 30)return 1;
		return 31;
	}
	if (start + num > 21)return 31;
	if (start + num == 21)return 1;
	return start + num;
}
char gR(int num, int ind) {
	if (loc[ind] == num)return 'A' + ind;
	if (loc2[ind] == num)return 'a' + ind;
	return '.';
}
void pr() {
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			b[i][j] = ' ';
			if (i == j)b[i][j] = '\\';
			if (i + j == 31)b[i][j] = '/';
		}
	}
	for (int i = 0; i < 32; i++) {
		b[i][0] = '|';
		b[i][31] = '|';
		b[0][i] = '-';
		b[31][i] = '-';
	}
	for (int i = 0; i < 6; i++) {
		b[0][i*6] = gR(11 - i, 0);
		b[0][1 + i*6] = gR(11 - i, 1);
		b[1][i*6] = gR(11 - i, 2);
		b[1][1 + i*6] = gR(11 - i, 3);
		b[30][i * 6] = gR(16 + i, 0);
		b[30][1 + i * 6] = gR(16 + i, 1);
		b[31][i * 6] = gR(16 + i, 2);
		b[31][1 + i * 6] = gR(16 + i, 3);
	}
	for (int i = 1; i <= 5; i++) {
		b[i*6][0] = gR(11 + i, 0);
		b[1+i*6][0] = gR(11 + i, 2);
		b[i * 6][1] = gR(11 + i, 1);
		b[1 + i * 6][1] = gR(11 + i, 3);
		b[i * 6][30] = gR(6 - i, 0);
		b[1 + i * 6][30] = gR(6 - i, 2);
		b[i * 6][31] = gR(6 - i, 1);
		b[1 + i * 6][31] = gR(6 - i, 3);
	}
	for (int i = 1; i < 3; i++) {
		b[i * 5][i * 5] = gR(25 + i, 0);
		b[i * 5][1 + i * 5] = gR(25 + i, 1);
		b[1 + i * 5][i * 5] = gR(25 + i, 2);
		b[1 + i * 5][1 + i * 5] = gR(25 + i, 3);
	}
	for (int i = 4; i < 6; i++) {
		b[i * 5][i * 5] = gR(24 + i, 0);
		b[i * 5][1 + i * 5] = gR(24 + i, 1);
		b[1 + i * 5][i * 5] = gR(24 + i, 2);
		b[1 + i * 5][1 + i * 5] = gR(24 + i, 3);
	}
	for (int i = 1; i < 6; i++) {
		b[31 - i * 5][i * 5] = gR(26 - i, 2);
		b[31 - i * 5][1 + i * 5] = gR(26 - i, 3);
		b[30 - i * 5][i * 5] = gR(26 - i, 0);
		b[30 - i * 5][1 + i * 5] = gR(26 - i, 1);
	}
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 32; j++) {
			cout << b[i][j];
		}
		cout << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--) {
		char in1;
		string in2;
		int cur, curLo, team;
		cin >> in1 >> in2;
		if (in1 >= 'A' && in1 <= 'D') {
			cur = in1 - 'A';
			curLo = loc[cur];
			team = 1;
		}
		else {
			cur = in1 - 'a';
			curLo = loc2[cur];
			team = 2;
		}
		int mv = gN(in2);
		int des = gD(curLo, mv);
		if (team == 1) {
			if (curLo == 0)loc[cur] = des;
			for (int i = 0; i < 4; i++) {
				if (loc2[i] == des)loc2[i] = 0;
				if (curLo != 0 && loc[i] == curLo)loc[i] = des;
			}
		}
		else {
			if (curLo == 0)loc2[cur] = des;
			for (int i = 0; i < 4; i++) {
				if (loc[i] == des)loc[i] = 0;
				if (curLo != 0 && loc2[i] == curLo)loc2[i] = des;
			}
		}
	}
	pr();
}