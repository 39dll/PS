#include <iostream>
#include <ios>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T = 0;
	cin >> T;
	int *p = new int[T], a, b;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		p[i] = a + b;
		cout << p[i] << "\n";
	}
	return 0;
}