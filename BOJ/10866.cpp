#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, temp = 0;
	deque<int> q;
	string a = "";
	cin >> N;
	while (N--) {
		cin >> a;
		if (a == "push_front") {
			cin >> temp;
			q.push_front(temp);
		}
		else if (a == "push_back") {
			cin >> temp;
			q.push_back(temp);
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
		else if (a == "pop_front") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop_front();
			}
			else cout << -1 << "\n";
		}
		else if (a == "pop_back") {
			if (!q.empty()) {
				cout << q.back() << "\n";
				q.pop_back();
			}
			else cout << -1 << "\n";
		}
	}
}