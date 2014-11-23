#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i = a; i <= n; ++i)

const int MAX = 110, MOD = 1000007;
int i, j, k, n, m, a[MAX], f[MAX];

int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) scanf("%d", &a[i]);
	f[0] = 1;
	FOR(i, 1, n) for(j = m; j >= 0; --j) FOR(k, 1, a[i]) if(j-k >= 0) f[j] = (f[j] + f[j-k]) % MOD;
	printf("%d", f[m]);
	return 0;
}
