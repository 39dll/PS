long long calc(long long A, long long B, long long C) {
	if (B == 1) { return (A % C); }
	long long temp = calc(A, B / 2) % C;
	if (B % 2 == 0) {
		return temp * temp % C;
	}
	else {
		return ((temp * temp) % C * (calc(A, 1))) % C;
	}
}
