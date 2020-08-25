#include <iostream>
#include <cmath>
using namespace std;
int N, white = 0, blue = 0, depth = 0;
bool a[65][65];
char temp[65];
void search(int depth, int startx, int starty) {
	int w, wt = 0, bl = 0;
	w = N / pow(2, depth);
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i + startx][j + starty] == 1) bl++;
			else wt++;
		}
	}
	if (wt == w*w) {
		cout << "0";
		return;
	}
	else if (bl == w*w) {
		cout << "1";
		return;
	}
	cout << "(";
	search(depth + 1, startx, starty);
	search(depth + 1, startx, starty + w / 2);
	search(depth + 1, startx + w / 2, starty);
	search(depth + 1, startx + w / 2, starty + w / 2);
	cout << ")";
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < N; j++) {
			a[i][j] = temp[j] - '0';
		}
	}
	search(0, 0, 0);
	return 0;
}