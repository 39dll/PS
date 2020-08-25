#include <iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	while (a != 0 && b != 0) {
		if (a%b == 0) cout << "multiple\n";
		else if (b%a == 0) cout << "factor\n";
		else cout << "neither\n";
		cin >> a >> b;
	}
	return 0;
}