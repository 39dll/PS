#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int T, n;
string p, input, num;
bool reversed = 0, error = 0;
deque<int> d;
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> T;
	while (T--) {
		error = 0; reversed = 0; num.clear();
		cin >> p;
		cin >> n;
		cin >> input;
		for (int i = 1; i < input.length(); i++) {
			if (input[i] != ']' && input[i] != ',' ) {
				num += input[i];
			}
			else {
				if (num != "") d.push_back(stoi(num));
				num.clear();
			}
		}
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				reversed ^= 1;
			}
			else {
				if (d.empty()) {
					error = 1;
					break;
				}
				if (reversed) d.pop_back();
				else d.pop_front();
			}
		}
		if (error == 1) cout << "error\n";
		else {
			cout << "[";
			if (!reversed) {
				while (!d.empty()) {
					cout << d.front();
					d.pop_front();
					if (!d.empty()) cout << ",";
				}
			}
			else {
				while (!d.empty()) {
					cout << d.back();
					d.pop_back();
					if (!d.empty()) cout << ",";
				}
			}
			cout << "]\n";
		}
	}
}