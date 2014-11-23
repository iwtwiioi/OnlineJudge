#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int maxn=15000, maxm=1000;
int f[maxn][maxm], a[maxn];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int i, j, k;
	FOR(i, 1, n) scanf("%d", &a[i]);
	FOR(i, 1, n) {
		f[i][0]=f[i-1][0];
		FOR(k, 1, i) if(k<=m) f[i][0]=max(f[i][0], f[i-k][k]);
		FOR(j, 1, m) f[i][j]=f[i-1][j-1]+a[i];
	}
	printf("%d\n", f[n][0]);
	return 0;
}

