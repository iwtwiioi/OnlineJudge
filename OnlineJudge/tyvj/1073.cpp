#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int maxn=35;
int f[maxn][maxn], a[maxn], root[maxn][maxn];

void dp(int i, int j) {
	if(i>j) { f[i][j]=1; return; }
	if(f[i][j]) return;
	int k;
	FOR(k, i, j) {
		dp(i, k-1); dp(k+1, j);
		if(f[i][j] < f[i][k-1]*f[k+1][j]+a[k]) {
			f[i][j]=f[i][k-1]*f[k+1][j]+a[k];
			root[i][j]=k;
		}
	}
}

void print(int i, int j) {
	printf("%d ", root[i][j]);
	if(i==root[i][j]-1) printf("%d ", i);
	else if(i<root[i][j]-1) print(i, root[i][j]-1);
	if(j==root[i][j]+1) printf("%d ", j);
	else if(j>root[i][j]+1) print(root[i][j]+1, j);
}

int main() {
	int n, i;
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &a[i]);
	FOR(i, 1, n) f[i][i]=a[i];
	dp(1, n);
	printf("%d\n", f[1][n]);
	print(1, n);
	return 0;
}

