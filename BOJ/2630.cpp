#include <iostream>
#include <cmath>
using namespace std;
int N, white = 0, blue = 0, depth = 0;
bool a[129][129];
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
		white++;
		return;
	}
	else if (bl == w*w) {
		blue++;
		return;
	}
	search(depth + 1, startx, starty);
	search(depth + 1, startx + w / 2, starty);
	search(depth + 1, startx, starty + w / 2);
	search(depth + 1, startx + w / 2, starty + w / 2);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	search(0, 0, 0);
	cout << white << "\n" << blue << "\n";
	return 0;
}