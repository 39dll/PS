#include <cstdio>
using namespace std;
int main() {
	int N, n, c = 0;
	scanf("%d\n", &N);
	while ((n = getchar()) != '\n') {
		c += n - '0';
	}
	printf("%d", c);
}