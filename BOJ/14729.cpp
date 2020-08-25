#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue<double, vector<double>, greater<double> > pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	double a;
	cout.precision(3);
	cin >> n;
	while (n--) {
		cin >> a;
		pq.push(a);
	}
	n = 7;
	while (n--) {
		cout << fixed << pq.top() << "\n";
		pq.pop();
	}
}