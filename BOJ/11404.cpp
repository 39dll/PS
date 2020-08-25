#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int N, M, dist[101][101];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 1; i <= M; i++) {
		int in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		dist[in1][in2] = min(dist[in1][in2], in3);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] != INF)cout << dist[i][j] << " ";
			else cout << "0 ";
		}
		cout << "\n";
	}
}