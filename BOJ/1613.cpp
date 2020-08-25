#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int N, M, K, dist[401][401];
int main() { //Floyd-Warshall로 100개의 도시의 이동 최소 비용 알아내기
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 1; i <= M; i++) {
		int in1, in2;
		cin >> in1 >> in2;
		dist[in1][in2] = min(dist[in1][in2], 1);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int in1, in2;
		cin >> in1 >> in2;
		if (dist[in1][in2] == INF && dist[in2][in1] == INF)cout << 0 << '\n';
		else if (dist[in1][in2] > dist[in2][in1])cout << 1 << '\n';
		else cout << -1 << '\n';
	}
}