#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
deque<int> d;
int N, A[1000001], ans;
int calc() {
	int cnt = 0;
	for (int i = 1; i < N; i++) {
		cnt += abs(A[i] - A[i + 1]);
	}
	return cnt;
}
int calc2() {
	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		cnt += abs(A[i] - A[i + 1]);
	}
	return cnt;
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; i++) {
		d.push_back(A[i]);
	}
	if (N % 2 == 0) {
		for (int i = 1; i <= N / 2; i++) {
			if (i % 2 == 1) {
				A[N / 2 - i + 1] = d.back();
				d.pop_back();
				A[N / 2 + i] = d.front();
				d.pop_front();
			}
			else {
				A[N / 2 - i + 1] = d.front();
				d.pop_front();
				A[N / 2 + i] = d.back();
				d.pop_back();
			}
		}
		ans = calc();
	}
	else {
		for (int i = 1; i <= (N - 1) / 2; i++) {
			if (i % 2 == 1) {
				A[N / 2 - i + 1] = d.back();
				d.pop_back();
				A[N / 2 + i] = d.front();
				d.pop_front();
			}
			else {
				A[N / 2 - i + 1] = d.front();
				d.pop_front();
				A[N / 2 + i] = d.back();
				d.pop_back();
			}
		}
		A[0] = A[N] = d.back();
		ans = max(calc(), calc2());
	}
	cout << ans;
}