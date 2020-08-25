#include <iostream>
using namespace std;
int N, M;
int a[10];
bool b[10];
void go(int dep) {
	if (dep == M) {
		for (int i = 0; i < M; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		//if (b[i]) continue;
		//b[i] = 1;
		a[dep] = i;
		go(dep + 1);
		//b[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		b[i] = 1;
		a[0] = i;
		go(1);
		b[i] = 0;
	}
	return 0;
}