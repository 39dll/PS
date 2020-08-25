#include <stack>
#include <iostream>
using namespace std;
int main() {
	int K, i, ans = 0;
	stack<int> a;
	cin >> K;
	while (K--) {
		cin >> i;
		if (i != 0) a.push(i);
		else a.pop();
	}
	for (int i = a.size(); i >= 1; i--) {
		ans += a.top();
		a.pop();
	}
	cout << ans;
	return 0;
}