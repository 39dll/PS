#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int N, ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int in;
		cin >> in;
		pq.push(in);
	}
	while (pq.size() > 1) {
		int int1 = pq.top();
		pq.pop();
		int int2 = pq.top();
		pq.pop();
		ans += int1 + int2;
		pq.push(int1 + int2);
	}
	cout << ans;
}