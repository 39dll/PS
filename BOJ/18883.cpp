#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int N, M, c = 1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << c;
			if(c%M!=0)cout<<" ";
			c++;
		}
		cout << "\n";
	}
}