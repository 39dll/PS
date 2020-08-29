#include <iostream>
using namespace std;
long long a[3][3], a2[3][3], ans[3][3], temp[3][3], N;
void mult(long long a[3][3], long long b[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				temp[i][j] += a[i][k] * b[k][j];
				temp[i][j] %= 1000000007;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = temp[i][j];
			temp[i][j] = 0;
		}
	}
}
int main() {//19587을 푸는 알고리즘
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N; N--;
	/*
	행렬 설명
	
	a : 가운데 거듭제곱되는 행렬
		초기화는 점화식으로 유도된 행렬로 한다.
	a2 : 거듭제곱된 결과가 저장되는 행렬
		초기화는 영행렬로 한다.
	temp : mult함수에서 사용되는 임시 행렬
	ans : 답이 저장되어 있는 행렬.
		초기화를 할 때는 ans[0][i]의 꼴로 베이스 값을 저장해놓는다.
	mult(ans, a2)를 하면 ans[0][i]에 원하는 값이 들어간다.
	
	*/
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = 1;
			if (i == j)a2[i][i] = 1;
		}
	}
	a[0][0] = a[1][1] = 0;
	ans[0][0] = ans[0][1] = ans[0][2] = 1;
	while (N > 0) {
		if (N % 2 == 1) {
			mult(a2, a);
		}
		mult(a, a);
		N /= 2;
	}
	mult(ans, a2);
	cout << (ans[0][0] + ans[0][1] + ans[0][2]) % 1000000007;
}