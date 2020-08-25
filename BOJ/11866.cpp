#include <iostream>
#include <queue>
using namespace std;
queue<int> a, b;
int N, K, temp;
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		a.push(i);
	}
	while (a.size()) {
		for (int i = 1; i <= K; i++) {
			if (i < K) {
				temp = a.front();
				a.pop();
				a.push(temp);
			}
			else {
				b.push(a.front());
				a.pop();
			}
		}
	}
	cout << "<";
	while (b.size()) {
		if(b.size()!=1) cout << b.front() << ", ";
		else cout << b.front();
		b.pop();
	}
	cout << ">";
	return 0;
}