#include <iostream>
#include <queue>
using namespace std;
queue<int> a;
int N, temp;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		a.push(i);
	}
	while (a.size() > 1) {
		a.pop();
		temp = a.front();
		a.pop();
		a.push(temp);
	}
	cout << a.front();
	return 0;
}