#include <iostream>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	if (x == 0) {
		if (y < 45) {
			cout << "23 " << y + 15;
		}
		else {
			cout << "0 " << y - 45;
		}
	}
	else if (y < 45) {
		cout << x - 1 << " " << y + 15;
	}
	else {
		cout << x << " " << y - 45;
	}
	return 0;
}