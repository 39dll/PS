#include <bits/stdc++.h>
using namespace std;

const long double pi = acos(-1);
typedef complex<double> base;

void fft(vector <base> &a, bool invert) {
	int n = a.size();
	for (int i = 1, j = 0; i<n; i++) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * pi / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i<n; i += len) {
			base w(1);
			for (int j = 0; j<len / 2; j++) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i = 0; i<n; i++) a[i] /= n;
}

vector<int> mul(const vector<int> &a, const vector<int> &b) {
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while (n < max(a.size(), b.size())) n <<= 1;
	n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa, false); fft(fb, false);
	for (int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, true);
	vector<int> res;
	res.resize(n);
	for (int i = 0; i < n; i++) res[i] = int(fa[i].real() + 0.5);
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	vector<int> v1, v2, res;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int in; cin >> in;
		v1.push_back(in);
	}
	for (int i = 0; i < M; i++) {
		int in; cin >> in;
		v2.push_back(in);
	}
	vector<int> res = mul(v1, v2);
	for (int i = 0; i < N + M - 1; i++) {
		cout << res[i] << ' ';
	}
}
