#include <iostream>
using namespace std;
int max(int a, int b) {	if (a > b) return a; else return b;}
int main() {
	int a1, a2, a3, a4, a5;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	
	cout << (max(a1,40) + max(a2,40) + max(a3,40) + max(a4,40) + max(a5,40)) / 5;
	return 0;
}