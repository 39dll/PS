#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
queue<int> a, b;
int arr[101];
int T, N, M, cnt = 1, temp;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			a.push(arr[i]);
		}
		sort(arr, arr + N);
		for (int i = 0; i < N; i++) {
			b.push(arr[N - i - 1]);
		}
		while (1) {
			if (M == 0 && a.front() == b.front()) {
				cout << cnt << "\n"; break;
			}
			else if (a.front() == b.front()) {
				a.pop(); b.pop(); M--; cnt++;
			}
			else {
				temp = a.front();
				a.pop();
				a.push(temp);
				if (M == 0) M = a.size() - 1;
				else M--;
			}
		}
		cnt = 1;
		while (!a.empty()) a.pop();
		while (!b.empty()) b.pop();
	}
	return 0;
}