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

const int N=105, oo=1000000000;
int f[N][N], a[N], p[N][N], sum[N], out[N], cnt=1;

int print(int i, int j) {
	if(i==j) { printf("%d", a[i]); return a[i]; }
	if(i>j) return 0;
	int t=0;
	printf("(");
	t+=print(i, p[i][j]);
	printf("+");
	t+=print(p[i][j]+1, j);
	printf(")");
	return out[cnt++]=t;
}

int main() {
	int n, i, j, k, t;
	rdin(n);
	FOR(i, 0, n) FOR(j, 0, n) f[i][j]=oo;
	FOR(i, 1, n) { rdin(a[i]); sum[i]=sum[i-1]+a[i]; f[i][i]=0; }
	FOR(j, 1, n) for(i=j; i>0; --i) FOR(k, i, j-1) {
		t=f[i][k]+f[k+1][j]+sum[j]-sum[i-1];
		if(f[i][j]>=t) {
			f[i][j]=t;
			p[i][j]=k;
		}
	}
	print(1, n);
	printf("\n%d\n", f[1][n]);
	FOR(i, 1, n-1) printf("%d ", out[i]);
	printf("\n");
	return 0;
}

