#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int MOD=1012;

int fastpow(int a, int b) {
	int ret=1;
	while(b) {
		if(b&1) ret=(ret*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ret;
}

int main() {
	int n, i, a, b;
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d%d", &a, &b);
		printf("%d\n", fastpow(a, b));
	}
	return 0;
}

