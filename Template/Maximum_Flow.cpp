#include <bits/stdc++.h>
using namespace std;
const int MAX = 800;
const long long INF = 2100000000;
int c[MAX][MAX], f[MAX][MAX], visited[MAX];
vector<int> edge[MAX];

/*
S에서 T로 가는 증가 경로 구하기(에드몬드 카프)
S : 시작점, T : 도착점
c[a][b] : a에서 b로 흐를 수 있는 최대 양 (Capacity)
f[a][b] : a에서 b로 흐른 실제 양 (Flow)

조건
용량 제한 : f[a][b] <= c[a][b]
유량의 대칭성 : f[a][b] == -f[a][b]
나오는 유량의 합 == 들어오는 유량의 합
*/

int maxFlow(int S, int T);
int bfs(int S, int T);

int maxFlow(int S, int T) {
	int result = 0;
	while (1) {
		int flow = bfs(S, T);
		if (!flow)break;
		result += flow;
	}
	return result;
}

int bfs(int S, int T) {
	memset(visited, -1, sizeof(visited));
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : edge[cur]) {
			//방문했는지, 용량이 남아 있는지 체크
			if (c[cur][next] - f[cur][next] <= 0)continue;
			if (visited[next] != -1)continue;
			q.push(next);
			visited[next] = cur; //cur->next 경로 기억
			if (next == T)break; //도착했을 경우 종료
		}
	}
	if (visited[T] == -1)return 0;
	int flow = INF;
	for (int i = T; i != S; i = visited[i]) { //최소 유량 탐색
		flow = min(flow, c[visited[i]][i] - f[visited[i]][i]);
	}
	for (int i = T; i != S; i = visited[i]) { //최소 유량 추가
		f[visited[i]][i] += flow;
		f[i][visited[i]] -= flow;
	}
	return flow;
}

int getInt(char c) {
	if (c <= 'Z')return c - 'A';
	return c - 'a' + 26;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char in1, in2; //A ~ Z : 0 ~ 25, a ~ z : 26 ~ 51
		int in3;
		cin >> in1 >> in2 >> in3;
		in1 = getInt(in1);
		in2 = getInt(in2);
		c[in1][in2] += in3;
		c[in2][in1] += in3;
		edge[in1].push_back(in2);
		edge[in2].push_back(in1);
	}
	cout << maxFlow(getInt('A'), getInt('Z'));
}
