#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define CAL(a,b) (abs(x[a]-x[b])*(b-a+1))

const int N=500;
int f[N][N], x[N], n;

int main() {
	scanf("%d", &n);
	int i, j, k;
	FOR(i, 1, n) { scanf("%d", &x[i]); f[i][i]=x[i]; }
	for(j=1; j<=n; ++j)
		for(i=j-1; i>0; --i) {
			f[i][j]=CAL(i, j);
			for(k=i; k<j; ++k)
				f[i][j]=max(f[i][j], f[i][k]+f[k+1][j]);
	}
	printf("%d\n", f[1][n]);
	return 0;
}

