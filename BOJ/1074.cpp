#include <iostream>
#include <cmath>
using namespace std;
long long N, r, c, sum;
void search(long long size) {//size*size의 사각형
	if (size == 1) {
		return;
	}
	long long k = size * pow(2, N - 2);
	if (size == 2) k = 1;
	N--;
	if (r < size / 2 && c < size / 2) {
		search(size / 2);
		return;
	}
	if (r < size / 2 && c >= size / 2) {
		sum += 2 * k;
		c -= size / 2;
		search(size / 2);
		return;
	}
	if (r >= size / 2 && c < size / 2) {
		sum += k;
		r -= size / 2;
		search(size / 2);
		return;
	}
	if (r >= size / 2  && c >= size / 2) {
		sum += 3 * k;
		c -= size / 2;
		r -= size / 2;
		search(size / 2);
		return;
	}
}
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> c >> r;
	search((long long)pow(2, N));
	cout << sum;
}