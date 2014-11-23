#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rdin(a) scanf("%d", &a)
#define prin(a) printf("%d", a);

unsigned int f[5000];

int main() {
	int n;
	rdin(n);
	int i, v;
	f[0]=1;
	FOR(v, 1, n-1)
		FOR(i, v, n) 
			f[i]=(f[i]+f[i-v])&2147483647;
	prin(f[n]);
	return 0;
}

