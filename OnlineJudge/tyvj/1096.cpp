#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N=105, M=10005;
int f[M], n, m;

int main() {
	scanf("%d%d", &n, &m);
	int i, j, a;
	f[0]=1;
	FOR(i, 1, n) {
		scanf("%d", &a);
		for(j=m; j>=a; --j)
			f[j]+=f[j-a];
	}
	printf("%d\n", f[m]);
	return 0;
}

