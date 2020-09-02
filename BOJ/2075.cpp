#include <bits/stdc++.h>
using namespace std;
int N, in;
priority_queue<int> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N*N; i++) {
		cin >> in;
		pq.push(-in);
		if (pq.size() <= N)continue;
		pq.pop();
	}
	cout << -pq.top();
}