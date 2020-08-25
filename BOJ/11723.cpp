#include <iostream>
#include <cmath>
#include <string>
using namespace std;
long long a;
int M, num;
string com;
void add(int x) {
	a |= (1 << x);
}
void remove(int x) {
	a &= ~(1 << x);
}
bool check(int x) {
	return a & (1 << x);
}
void toggle(int x) {
	if (check(x)) remove(x);
	else add(x);
}
void all() {
	a = pow(2, 21) - 1;
}
void empty() {
	a = 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M;
	while (M--) {
		cin >> com;
		if (com == "add") {
			cin >> num;
			add(num);
		}
		else if (com == "remove") {
			cin >> num;
			remove(num);
		}
		else if (com == "check") {
			cin >> num;
			cout << check(num) << "\n";
		}
		else if (com == "toggle") {
			cin >> num;
			toggle(num);
		}
		else if (com == "all") {
			all();
		}
		else if (com == "empty") {
			empty();
		}
	}
}