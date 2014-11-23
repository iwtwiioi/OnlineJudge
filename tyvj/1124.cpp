#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N=105, oo=-1000000000;
int f[N][N], p[N][N], n, v, imap[N][N];

void print(int i, int j) {
	if(i>1) print(i-1, p[i][j]);
	printf("%d ", j);
}

int main() {
	scanf("%d%d", &n, &v);
	int i, j, k, ans=0;
	FOR(i, 1, n) FOR(j, 1, v) scanf("%d", &imap[i][j]);
	FOR(i, 0, n) FOR(j, 0, v) f[i][j]=oo;
	FOR(i, 1, v) f[1][i]=imap[1][i];
	FOR(i, 2, n) FOR(j, i, v) {
		FOR(k, i-1, j-1) if(f[i-1][k]>f[i][j]) {
			f[i][j]=f[i-1][k]; p[i][j]=k;
		}
		f[i][j]+=imap[i][j];
	}
	FOR(i, 1, v) if(ans<f[n][i]) ans=f[n][i], j=i;
	printf("%d\n", ans);
	print(n, j);
	printf("\n");
	return 0;
}

