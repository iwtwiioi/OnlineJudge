#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
const int maxn = 104, oo = 100000000;
int n, ans, a[maxn], f[maxn][maxn];
int min(const int& a, const int& b){return a < b ? a : b;}

int main() {
	
	int i, j, k;
	scanf("%d", &n);
	
	FOR(i, 1, n) scanf("%d", &a[i]);
	FOR(i, 1, n) FOR(j, i+2, n) f[i][j] = oo;
	FOR(j, 3, n) for(i = j-2; i > 0; --i) FOR(k, i+1, j-1)
		f[i][j] = min(f[i][j], f[i][k]+f[k][j]+a[i]*a[k]*a[j]);
	
	printf("%d\n", f[1][n]);
	
	return 0;
}
