#include <bits/stdc++.h>
using namespace std;
int N, H, T;
int arr[100001];
priority_queue<int> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> H >> T;
	for (int i = 0; i < N; i++) {
		int in;
		cin >> in;
		pq.push(in);
	}
	if (pq.top() < H) {
		cout << "YES\n0";
		return 0;
	}
	for (int t = 1; t <= T; t++) {
		int cur = pq.top();
		pq.pop();
		if (cur != 1)pq.push(cur / 2);
		else pq.push(1);
		if (pq.top() < H) {
			cout << "YES\n";
			cout << t;
			return 0;
		}
	}
	cout << "NO\n";
	cout << pq.top();
}
