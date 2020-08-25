#include <iostream>
#include <cmath>
using namespace std;
int N, one = 0, zero = 0, minusone = 0;
short a[2188][2188];
void search(int depth, int startx, int starty) {
	int w, o = 0, z = 0, mo = 0;
	w = N / pow(3, depth);
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i + startx][j + starty] == 1) o++;
			else if (a[i + startx][j + starty] == 0) z++;
			else mo++;
		}
	}
	if (o == w*w) {
		one++;
		return;
	}
	else if (z == w*w) {
		zero++;
		return;
	}
	else if (mo == w*w) {
		minusone++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			search(depth + 1, startx + w * i / 3, starty + w * j / 3);
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	search(0, 0, 0);
	cout << minusone << "\n" << zero << "\n" << one;
	return 0;
}