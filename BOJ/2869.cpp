#include <iostream>
using namespace std;
int main() {
	int A, B, V, d;
	cin >> A >> B >> V;
	d = (V - B - 1) / (A - B) + 1;
	cout << d;
	return 0;
}