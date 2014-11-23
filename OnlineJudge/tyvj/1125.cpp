#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N=105, K=60, oo=1000000000;
int f[N][K], c[N];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	k+=3;
	if(n<(k<<1)) { printf("-1\n"); return 0; }
	int i, j;
	FOR(i, 1, n) scanf("%d", &c[i]);
	sort(c+1, c+1+n);
	FOR(i, 0, n) FOR(j, 1, k) f[i][j]=oo;
	FOR(i, 1, n) FOR(j, 1, min(k, i>>1)) {
		f[i][j]=min(f[i][j], f[i-1][j]);
		if(i>1) f[i][j]=min(f[i][j], f[i-2][j-1]+(c[i]-c[i-1])*(c[i]-c[i-1]));
	}
	printf("%d\n", f[n][k]);
	return 0;
}

