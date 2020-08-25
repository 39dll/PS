#include <iostream>
using namespace std;
int inorder[100001], postorder[100001], preorder[100001];
int n, iter = 1;
void search(int instart, int inend, int poststart, int postend) {
	if (instart > inend || poststart > postend) return;
	int root = postorder[postend];
	preorder[iter] = root;
	iter++;
	if (instart == inend) return;
	for (int i = instart; i <= inend; i++) {
		if (inorder[i] == root) {
			search(instart, i - 1, poststart, poststart + i - instart - 1);
			search(i + 1, inend, poststart + i - instart, postend - 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inorder[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> postorder[i];
	}
	search(1, n, 1, n);
	for (int i = 1; i <= n; i++) {
		cout << preorder[i] << " ";
	}
}