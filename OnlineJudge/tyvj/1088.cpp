#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N=2005;
int n, a[N], f[N][N];
void dp(int i, int j, int t) {
	if(f[i][j]) return;
	if(i==j) { f[i][i]=a[i]*t; return; }
	dp(i+1, j, t+1); dp(i, j-1, t+1);
	f[i][j]=max(f[i+1][j]+a[i]*t, f[i][j-1]+a[j]*t);
}

int main() {
	scanf("%d", &n);
	int i;
	FOR(i, 1, n) scanf("%d", &a[i]);
	dp(1, n, 1);
	printf("%d\n", f[1][n]);
	return 0;
}

