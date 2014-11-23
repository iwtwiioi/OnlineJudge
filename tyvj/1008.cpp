#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
int f[40][40], n, m, i, j, k;
int main() {
	scanf("%d%d", &n, &m);
	f[1][0] = 1;
	FOR(k, 1, m) FOR(i, 1, n) {
		if(i == 1) f[i][k] = f[n][k-1]+f[2][k-1];
		else if(i == n) f[i][k] = f[n-1][k-1] + f[1][k-1];
		else f[i][k] = f[i-1][k-1] + f[i+1][k-1];
	}
	printf("%d\n", f[1][m]);
	return 0;
}
