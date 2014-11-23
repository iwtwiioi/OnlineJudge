#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
 
const int MAXN=500;
const int INF=1000000000;
int w[MAXN], n, m, f[MAXN][MAXN][2], sum[MAXN];
int i, j, k;
 
int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) FOR(j, 1, n) f[i][j][0]=INF;
	FOR(i, 1, n) { scanf("%d", &w[i]); f[i][i][0]=0; sum[i]+=sum[i-1]+w[i]; }
	for(j=1; j<=n; ++j)
		for(i=j; i>0; --i)
			for(k=i; k<j; ++k)
				f[i][j][0]=min(f[i][j][0], f[i][k][0]+f[k+1][j][0]+sum[j]-sum[i-1]),
				f[i][j][1]=max(f[i][j][1], f[i][k][1]+f[k+1][j][1]+sum[j]-sum[i-1]);
	if(m>f[1][n][1]) printf("It is easy\n");
	else if(m<f[1][n][0]) printf("I am..Sha...X\n");
	else printf("I will go to play WarIII\n");
	return 0;
}
