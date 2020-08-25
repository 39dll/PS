#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int x, y, x2, y2, x3, y3, x4, y4;
	cin >> x >> y >> x2 >> y2 >> x3 >> y3;
	if (x == x2) x4 = x3;
	else if (x == x3) x4 = x2;
	else if (x2 == x3) x4 = x;
	if (y == y2) y4 = y3;
	else if (y == y3) y4 = y2;
	else if (y2 == y3) y4 = y;
	cout << x4 << " " << y4;
	return 0;
}