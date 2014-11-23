#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N=1100, oo=1000000000;
int sum[N], w[N], d[N], f[N][N][2], n, v;

int dp(int i, int j, int k) {
	if(f[i][j][k]!=-1) return f[i][j][k];
	f[i][j][k]=oo;
	if(!k) {
		if(i>=1) f[i][j][k]=min(f[i][j][k], dp(i-1, j, 0)+abs(d[i]-d[i-1])*(sum[n]-sum[j]+sum[i-1]));
		if(j<=n) f[i][j][k]=min(f[i][j][k], dp(i, j+1, 1)+abs(d[j+1]-d[i])*(sum[n]-sum[j]+sum[i-1]));
	}
	else {
		if(i>=1) f[i][j][k]=min(f[i][j][k], dp(i-1, j, 0)+abs(d[j]-d[i-1])*(sum[n]-sum[j]+sum[i-1]));
		if(j<=n) f[i][j][k]=min(f[i][j][k], dp(i, j+1, 1)+abs(d[j+1]-d[j])*(sum[n]-sum[j]+sum[i-1]));
	}
	return f[i][j][k];
}

int main() {
	scanf("%d%d", &n, &v);
	int i;
	FOR(i, 1, n) {
		scanf("%d%d", &d[i], &w[i]);
		sum[i]=sum[i-1]+w[i];
	}
	CC(f, -1);
	f[0][n+1][0]=f[0][n+1][1]=0;
	printf("%d\n", dp(v, v, 0));
		
	return 0;
}

