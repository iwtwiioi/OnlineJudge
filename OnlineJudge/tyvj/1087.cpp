#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N=1000005, MOD=1000000000;
int f[N], n;

int main() {
	scanf("%d", &n);
	f[1]=1; f[2]=2;
	int i;
	FOR(i, 3, n)
		if(i&1) f[i]=f[i-1];
		else f[i]=(f[i-1]+f[i>>1])%MOD;
	printf("%d", f[n]);
	return 0;
}

