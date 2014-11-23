#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i = a; i <= n; ++i)

const int MAX = 110, MOD = 1000007;
int i, j, k, n, m, a[MAX], f[MAX][MAX];

int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) scanf("%d", &a[i]);
	f[0][0] = 1;
	FOR(i, 1, n) FOR(j, 0, m) FOR(k, 0, a[i]) if(j-k >= 0) f[i][j] = (f[i][j] + f[i-1][j-k]) % MOD;
	printf("%d", f[n][m]);
	return 0;
}