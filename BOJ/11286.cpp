#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	priority_queue<double> a;
	int N;
	double x;
	cin >> N;
	while (N--) {
		cin >> x;
		if (x != 0) {
			if (x < 0) x += 0.5;
			a.push(2147483648 - abs(x));
		}
		else {
			if (a.empty()) cout << "0\n";
			else {
				if(a.top() == floor(a.top())) cout << int(2147483648 - a.top()) << "\n";
				else cout << int(a.top() - 2147483648 - 0.5) << "\n";
				a.pop();
			}
		}
	}
}