#include <iostream>
using namespace std;
double a, b, c;
int main() {
	cin >> a >> b >> c;
	cout.precision(10);
	cout << fixed << a * c / b;
}