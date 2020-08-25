#include <iostream>
#include <utility>
using namespace std;
bool map[1001][1001], visited[1001][1001] = { 0, };
int N, M, L, R, x, y, temp, ans = 0;
void search(const int xx, const int yy, const int LL , const int RR, bool Lmove, bool Rmove, bool Umove, bool Dmove) {
	int a = xx, b = yy; cout << "visited[" << a << "][" << b << "] = " << 1 << "\n";
	visited[a][b] = 1; 
	if ((b < M) && !Umove && !map[a][b + 1] && !visited[a][b + 1]) search(a, b + 1, LL, RR, 0, 0, 0, 1);
	if ((b > 1) && !Dmove && !map[a][b - 1] && !visited[a][b - 1]) search(a, b - 1, LL, RR, 0, 0, 1, 0);
	if ((a < N) && !Lmove && !map[a + 1][b] && !visited[a + 1][b] && (RR > 0)) search(a + 1, b, LL, RR - 1, 0, 1, 0, 0);
	if ((a > 1) && !Rmove && !map[a - 1][b] && !visited[a - 1][b] && (LL > 0)) search(a - 1, b, LL - 1, RR, 1, 0, 0, 0);
	
}
int main() {
	cin >> N >> M >> L >> R;
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= M; i++) {
			cin >> temp;
			if (temp != 2) {
				map[i][j] = temp;
			}
			else { x = i; y = j; map[i][j] = 0; }
		}
	}
	search(x, y, L, R, 0, 0, 0, 0);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << visited[i][j];
			ans += visited[i][j];
		}
		cout << "\n";
	}
	cout << ans;
}