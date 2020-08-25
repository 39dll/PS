#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, temp = 0;
	queue<int> q;
	string a = "";
	cin >> N;
	while (N--) {
		cin >> a;
		if (a == "push") {
			cin >> temp;
			q.push(temp);
		}
		else if (a == "front") {
			if (!q.empty()) cout << q.front() << "\n";
			else cout << -1 << "\n";
		}
		else if (a == "back") {
			if (!q.empty()) cout << q.back() << "\n";
			else cout << -1 << "\n";
		}
		else if (a == "size") {
			cout << q.size() << "\n";
		}
		else if (a == "empty") {
			cout << q.empty() << "\n";
		}
		else if (a == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << -1 << "\n";
		}
	}
}