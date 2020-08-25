#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> child[123457];
char t[123458];
int par[123457];
long long a[123457];
long long sheepstack[123457];
void search(int ind) {
	int childcnt = child[ind].size();
	if (childcnt == 0 && t[ind] == 'W') return;
	for (int i = 0; i < childcnt; i++) {
		int next = child[ind][i];
		search(next);
	}
	if (ind == 1 || sheepstack[ind] == 0)return;
	if (t[par[ind]] == 'S') {
		sheepstack[par[ind]] += sheepstack[ind];
	}
	else {
		sheepstack[par[ind]] = sheepstack[ind] - a[par[ind]] + sheepstack[par[ind]];
		a[par[ind]] = max(0LL, a[par[ind]] - sheepstack[ind]);
		if (sheepstack[par[ind]] < 0)sheepstack[par[ind]] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	t[1] = 'S';
	for (int i = 2; i <= N; i++) {
		char in1;
		int in2, in3;
		cin >> in1 >> in2 >> in3;
		t[i] = in1;
		a[i] = in2;
		child[in3].push_back(i);
		par[i] = in3;
		if (in1 == 'S')sheepstack[i] = in2;
	}
	search(1);
	cout << sheepstack[1];
}