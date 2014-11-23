#include <cstdio>
using namespace std;
typedef unsigned long long ull;
ull fastpow(ull a, ull b, int c) {
	ull ret=1;
	while(b) {
		if(b&1) ret=(ret*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return ret;
}

int main() {
	ull n, m;
	scanf("%llu%llu", &m, &n);
	printf("%llu\n", (fastpow(m, n, 100003)+100003-((ull)(m%100003)*fastpow(m-1, n-1, 100003))%100003)%100003);
	return 0;
}
