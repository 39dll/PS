#include <bits/stdc++.h>
using namespace std;
typedef pair < pair<int, int>, int > p;
typedef tuple<int, int, int, bool> t;
int N, M, K;
queue<p> q[100001];
priority_queue<t> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int in1, in2;
		int put = i % M;
		cin >> in1 >> in2;
		if (i < M) {
			pq.push({ in1,in2,-put,i == K });
		}
		else q[put].push({ {in1,in2},i == K });
	}
	int ans = 0;
	while (get<3>(pq.top()) != 1) {
		int line = -get<2>(pq.top());
		pq.pop();
		if (!q[line].empty()) {
			int a = q[line].front().first.first;
			int b = q[line].front().first.second;
			bool ishim = q[line].front().second;
			q[line].pop();
			pq.push({ a,b,-line,ishim });
		}
		ans++;
	}
	cout << ans;
}
