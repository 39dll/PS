#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int N, K, sam[100001];
map<int, bool> visited;
queue<p> q;
int main() {
	cin >> N >> K;
	int cnt = 0;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> sam[i];
		visited[sam[i]] = 1;
	}
	for (int i = 0; i < N; i++) {
		int cur = sam[i];
		if (visited.find(cur + 1) == visited.end()) {
			q.push({ cur + 1, 1 });
			visited[cur + 1] = 1;
		}
		if (visited.find(cur - 1) == visited.end()) {
			q.push({ cur - 1, 1 });
			visited[cur - 1] = 1;
		}
	}
	while (cnt < K) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();
		ans += cost;
		cnt++;
		if (visited.find(cur + 1) == visited.end()) {
			q.push({ cur + 1, cost + 1 });
			visited[cur + 1] = 1;
		}
		if (visited.find(cur - 1) == visited.end()) {
			q.push({ cur - 1, cost + 1 });
			visited[cur - 1] = 1;
		}
	}
	cout << ans;
}