#include <iostream>
int min(int a, int b) { if (a < b) return a; else return b; }
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(min(w - x, x), min(h - y, y));
	return 0;
}