#include <iostream>
using namespace std;
int min(int a, int b) {	if (a < b) return a; else return b;}
int main() {
	int a1, a2, a3, a4, a5;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	cout << min(min(a1, a2), a3) + min(a4, a5) - 50;
	return 0;
}