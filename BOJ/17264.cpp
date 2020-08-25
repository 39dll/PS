#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N, P, W, L, G, point = 0, temp, lose;
string name[1001], gamer = "";
char win[1001];
int main() {
	cin >> N >> P >> W >> L >> G;
	for (int i = 0; i < P; i++) {
		cin >> name[i] >> win[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> gamer;
		for (int i = 0; i < P; i++) {
			if (gamer == name[i]) {
				temp = i; break;
			}
			if (i == P - 1) {
				lose = 1;
			}
		}
		if (lose == 1) {
			point -= L;
			point = max(point, 0);
			lose = 0;
		}
		else {
			if (win[temp] == 'W') {
				point += W;
				if (point >= G) break;
			}
			else {
				point -= L;
				point = max(point, 0);
			}
		}
	}
	if (point >= G) cout << "I AM NOT IRONMAN!!\n";
	else cout << "I AM IRONMAN!!\n";
	return 0;
}