#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int maxn=20;
int f[maxn][maxn], n, K, sum[maxn], a[maxn];

int main() {
	scanf("%d%d", &n, &K);
	int i, j, k;
	FOR(i, 1, n) { scanf("%d", &a[i]); sum[i]=sum[i-1]+a[i]; f[i][0]=sum[i]; }
	FOR(j, 1, K) FOR(i, 1, n) FOR(k, j, i-1)
		f[i][j]=max(f[i][j], f[k][j-1]*(sum[i]-sum[k]));
	printf("%d\n", f[n][K]);
	return 0;
}

