#include <bits/stdc++.h>
using namespace std;
int N, L, c, arr[1000001];
typedef pair<int, int> p;
priority_queue<p> pq;
priority_queue<p, vector<p>, greater<p>> pq2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> L >> c;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	bool none = 1;
	for (int i = 0; i < N; i++) {
		pq.push({ arr[i],i });
		pq2.push({ arr[i],i });
		while (pq.top().second <= i - L) pq.pop();
		while (pq2.top().second <= i - L) pq2.pop();
		if (pq.top().first - pq2.top().first <= c) {
			if (i + 1 < L)continue;
			cout << i - L + 2 << '\n';
			none = 0;
		}
	}
	if (none == 1)cout << "NONE";
}