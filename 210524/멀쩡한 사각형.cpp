using namespace std;
long long  gcd(long long a, long long  b) {
	long long  tmp, n;

	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

long long solution(int w, int h) {
	long long answer = 1;
	long long g = gcd((long long)w, (long long)h);

	answer = (long long)w * (long long)h - ((long long)w + (long long)h - g);
	return answer;
}