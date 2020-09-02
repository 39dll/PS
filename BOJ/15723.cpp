#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int N, M, Q, dist[27][27];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M; N = 26;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 1; i <= M; i++) {
		char i1, i2;
		string gar;
		cin >> i1 >> gar >> i2;
		dist[i1 - 'a' + 1][i2 - 'a' + 1] = min(dist[i1 - 'a' + 1][i2 - 'a' + 1], 1);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		char i1, i2;
		string gar;
		cin >> i1 >> gar >> i2;
		if (dist[i1 - 'a' + 1][i2 - 'a' + 1] != INF)cout << "T\n";
		else cout << "F\n";
	}
}