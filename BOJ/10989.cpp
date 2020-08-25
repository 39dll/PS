#include <stdio.h>
using namespace std;
int main() {
	int N, k;
	scanf("%d", &N);
	int a[10001] = { 0, };
	for (int i = 0; i < N; i++) {
		scanf("%d",&k); a[k]++;
	}
	for (int i = 0; i < 10001; i++) {
		if (a[i] != 0) {
			while (a[i] != 0) {
				printf("%d\n", i); a[i]--;
			}
		}
	}
	return 0;
}