#include <iostream>
#include <algorithm>
using namespace std;
bool jip[27][27] = { { 0, }, }, searched[27][27] = { { 0, }, }, searchsuccess = 0;
int N, danji[626] = { 0, }, ind = 1;
char str[27];
void dfs(int x, int y) {
	if (searched[x][y]) return;
	searched[x][y] = 1;
	if (jip[x][y] == 0) return;
	searchsuccess = 1;
	danji[ind]++;
	if (searched[x + 1][y] == 0 && jip[x + 1][y] == 1) dfs(x + 1, y);
	if (searched[x - 1][y] == 0 && jip[x - 1][y] == 1) dfs(x - 1, y);
	if (searched[x][y + 1] == 0 && jip[x][y + 1] == 1) dfs(x, y + 1);
	if (searched[x][y - 1] == 0 && jip[x][y - 1] == 1) dfs(x, y - 1);
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= N; j++) {
			jip[i][j] = str[j-1] - '0';
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dfs(i, j);
			if (searchsuccess) ind++;
			searchsuccess = 0;
		}
	}
	sort(danji + 1, danji + ind);
	cout << ind - 1 << "\n";
	for (int i = 1; i <= ind - 1; i++) {
		cout << danji[i] << "\n";
	}
}