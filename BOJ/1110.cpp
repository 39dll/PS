#include <iostream>
using namespace std;

int main() {
	int a, i, n = 0;
	cin >> i;
	a = i;
	i = ((i % 10) + (i / 10))%10 + 10*(i%10); n++;
	while (a != i) {
	i = ((i % 10) + (i / 10)) % 10 + 10 * (i % 10); n++;
	}
	cout << n;
	return 0;
}