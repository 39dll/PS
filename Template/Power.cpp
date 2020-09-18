long long mypow(long long A, long long B, long long C) {
	if (B == 0)return 1;
	if (B == 1)return (A % C);
	long long temp = mypow(A, B / 2, C) % C;
	if (B % 2 == 0)return temp * temp % C;
	return ((temp * temp) % C * (mypow(A, 1, C))) % C;
}
