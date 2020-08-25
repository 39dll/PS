#include <iostream>
using namespace std;
int main() {
	int m[8];
	bool asc = 1, dsc = 1;
	for (int i = 0; i < 8; i++) {
		cin >> m[i];
		if (m[i] != i + 1)asc = 0;
		if (m[i] != 8 - i)dsc = 0;
	}
	if (asc == 1)cout << "ascending";
	else if (dsc == 1)cout << "descending";
	else cout << "mixed";
}