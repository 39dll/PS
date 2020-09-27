#include<bits/stdc++.h>
using namespace std;
long long ch, score;
int ans[11], dap[11];
void backtrack(int n) {
	if (n >= 2) {
		if (ans[n - 2] == ans[n - 1] && ans[n - 1] == ans[n])return;
	}
	if (n == 9) {
		if (score >= 5)ch++;
		return;
	}
	for (int i = 1; i <= 5; i++) {
		ans[n + 1] = i;
		if (i == dap[n + 1])score++;
		backtrack(n + 1);
		if (i == dap[n + 1])score--;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++)cin >> dap[i];
	for (int i = 1; i <= 5; i++) {
		ans[0] = i;
		if (i == dap[0])score++;
		backtrack(0);
		if (i == dap[0])score--;
	}
	cout << ch;
}
