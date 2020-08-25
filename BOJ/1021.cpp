#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int N, M, temp, num = 0, cnt = 0;
deque<int> a, b;
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		a.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		b.push_back(temp);
	}
	while (1) {
		if (b.front() == a.front()) {
			cnt += min(num, (int)a.size() - num);
			num = 0;
			a.pop_front(); b.pop_front();
		}
		else {
			temp = a.front();
			a.pop_front();
			a.push_back(temp);
			num++;
		}
		if (b.empty()) break;
	}
	cout << cnt;
}