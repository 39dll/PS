#include <cstdio>
using namespace std;
int main() {
	char S[100] = { 0, };
	int c[26];
	int a;
	for (int i = 0; i < 26; i++) {
		c[i] = -1;
	}
	for (int i = 0; i < 100; i++) {
		if ((a = getchar()) != '\n') {
			S[i] = a;
		}
		else break;
	}
	for (int i = 0; i < 100; i++) {
		if (S[i] >= 'a' && S[i] <= 'z' && c[S[i]-'a'] == -1) {
			c[S[i] - 'a'] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ",c[i]);
	}
}