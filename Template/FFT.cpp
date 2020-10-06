#include <bits/stdc++.h>
using namespace std;

typedef complex<long double> cpx;
typedef vector<cpx> vec;
const long double pi = acos(-1);

void FFT(vec &f, cpx w) {
	int n = f.size();
	if (n == 1) return;
	vec even(n >> 1), odd(n >> 1);
	for (int i = 0; i < n; i++) {
		if (i & 1) odd[i >> 1] = f[i];
		else even[i >> 1] = f[i];
	}
	FFT(even, w*w); FFT(odd, w*w);
	cpx wp(1, 0);
	for (int i = 0; i < n / 2; i++) {
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp = wp * w;
	}
}

/*
input : vector a, b
output : vector containing convolusion of a and b
size of res : a.size() + b.size() - 1
*/
vec mul(vec a, vec b) {
	long long n = 1;

	while (n <= a.size() || n <= b.size()) n <<= 1;
	n <<= 1;
	a.resize(n); b.resize(n); vec c(n);

	//principal n-th root of unity
	cpx w(cos(2 * pi / n), sin(2 * pi / n));

	//a와 b의 DFT구하기
	FFT(a, w); FFT(b, w);

	//f(x) * g(x) = h(x)
	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];

	//켤레 복소수로 DFT -> IDFT
	FFT(c, cpx(w.real(), -w.imag()));
	for (int i = 0; i < n; i++) {
		c[i] /= cpx(n, 0);

		//만약 정수 결과를 원한다면
		//c[i] = cpx(round(c[i].real()), round(c[i].imag())); 
	}
	return c;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string a, b;
	cin >> a >> b;
	if (a == "0" || b == "0") {
		cout << 0;
		return 0;
	}
	int sz = a.size() + b.size() - 1;
	vec v1, v2;
	for (int i = 0; i < a.length(); i++) {
		v1.push_back(a[i] - '0');
	}
	for (int i = 0; i < b.length(); i++) {
		v2.push_back(b[i] - '0');
	}
	vec res;
	res = mul(v1, v2);
	vector<int> ans(sz + 1);
	for (int i = sz - 1; i >= 0; i--) {
		ans[i] += res[i].real() / 10;
		ans[i + 1] += (int)res[i].real() % 10;
		if (ans[i + 1] >= 10) {
			ans[i] += ans[i + 1] / 10;
			ans[i + 1] %= 10;
		}
	}
	for (int i = 0; i < sz + 1; i++) {
		if (i == 0 && ans[0] == 0)continue;
		cout << ans[i];
	}
}
