#include <iostream>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> p;
int N, K;
bool visited[100001];
priority_queue<p, vector<p>, greater<p>> pq;//cnt, num
int search(int N, int K) {
	pq.push({ 0,N });
	visited[N] = 1;
	while (!pq.empty()) {
		int cnt = pq.top().first;
		int num = pq.top().second;
		pq.pop();
		if (num == K)return cnt;
		if (num <= 50000 && !visited[2 * num]) {
			pq.push({ cnt,num * 2 });
			visited[num * 2] = 1;
		}
		if (num <= 99999 && !visited[num + 1]) {
			pq.push({ cnt + 1,num + 1 });
			visited[num + 1] = 1;
		}
		if (num >= 1 && !visited[num - 1]) {
			pq.push({ cnt + 1,num - 1 });
			visited[num - 1] = 1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	cout << search(N, K);
}