#include <iostream>
#include <cmath>
using namespace std;
long long G, cnt;
double t;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> G;
	t = sqrt(G);
	for (long long i = ceil(t); i*i - (i - 1)*(i - 1) <= G; i++) {
		for (long long a = 1; a < i; a++) {
			if (i * i - G == a * a) {
				cout << i << "\n";
				cnt++;
			}
		}
	}
	if (cnt == 0) {
		cout << -1;
	}
}