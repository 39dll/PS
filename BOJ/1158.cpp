#include <iostream>
#include <queue>
using namespace std;
queue<int> a;
int N, K, temp;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		a.push(i);
	}
	cout << "<";
	while (a.size()) {
		for (int i = 1; i <= K; i++) {
			if (i < K) {
				temp = a.front();
				a.pop();
				a.push(temp);
			}
			else {
				if (a.size() != 1) cout << a.front() << ", ";
				else cout << a.front();
				a.pop();
			}
		}
	}
	cout << ">";
	return 0;
}