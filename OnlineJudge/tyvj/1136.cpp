#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N=1050;
int f[N][N], a[N][N], n, m, ans;

int main() {
	scanf("%d%d", &n, &m);
	int i, j;
	FOR(i, 1, n) FOR(j, 1, m) {
		scanf("%d", &a[i][j]);
		if(j>1 && a[i][j-1] && !a[i][j]) ans=f[i][j]=1;
	}
	FOR(i, 2, n) FOR(j, 2, m) {
		if(f[i][j-1]==f[i-1][j] && f[i][j-1] && a[i-f[i][j-1]][j-1-f[i][j-1]])
			f[i][j]=f[i][j-1]+1;
		ans=max(ans, f[i][j]);
	}
	printf("%d", ans);
	return 0;
}

