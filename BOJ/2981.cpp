#include <bits/stdc++.h>
using namespace std;
int N, in[101];
int gcd(int a, int b) {
	int n;
	if (a < b)swap(a, b);
	while (b != 0) {
		n = a%b;
		a = b;
		b = n;
	}
	return a;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	int ans = -1;
	for (int i = 0; i < N; i++)cin >> in[i];
	sort(in, in + N);
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (ans == -1)ans = in[j] - in[i];
			else {
				ans = gcd(ans, in[j] - in[i]);
			}
		}
	}
	priority_queue<int> pq;
	pq.push(-ans);
	for (int i = 2; i <= sqrt(ans); i++) {
		if (ans%i == 0) {
			pq.push(-i);
			if (i*i != ans)pq.push(-ans / i);
		}
	}
	while (!pq.empty()) {
		cout << -pq.top() << ' ';
		pq.pop();
	}
}