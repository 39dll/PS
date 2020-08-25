#include <iostream>
#include <cmath>
using namespace std;
int N, res;
double a;
bool pressed;
int main() {
	cin >> N;
	while (N--) {
		cin >> a;
		if (pressed) {
			if (a == 0.5 || a == 0) {
				continue;
			}
			res += ceil(a - 0.5);
		}
		else {
			if (a == 0) continue;
			res += ceil(a);
			pressed = 1;
		}
	}
	cout << res;
}