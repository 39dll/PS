#include <iostream>
#include <queue>
using namespace std;
int N, K;
int cnt[100002] = { 0 };
bool visited[100002] = { 0 };
queue<int> q;
int main() {
	cin >> N >> K;
	q.push(N);
	visited[N]++;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (visited[p + 1] == 0 && p <= 99999) {
			q.push(p + 1);
			cnt[p + 1] = cnt[p] + 1;
			visited[p + 1] = 1;
		}
		if (visited[p - 1] == 0 && p > 0) {
			q.push(p - 1);
			cnt[p - 1] = cnt[p] + 1;
			visited[p - 1] = 1;
		}
		if (visited[p * 2] == 0 && p <= 50000) {
			q.push(p * 2);
			cnt[p * 2] = cnt[p] + 1;
			visited[p * 2] = 1;
		}
	}
	cout << cnt[K];
}