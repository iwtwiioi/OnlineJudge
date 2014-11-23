#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i = a; i <= n; ++i)
#define DFOR(i, a, n) for(i = a; i >= n; --i)
const int maxn = 110;
int n, a[maxn], f[maxn][2], i, j, ans;
int max(const int& a, const int& b) { return a > b ? a : b; }

int main() {
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &a[i]);
	FOR(i, 1, n) f[i][0] = f[i][1] = 1;
	FOR(i, 1, n) FOR(j, 1, i-1)
		if(a[i] > a[j] && f[i][0] < f[j][0] + 1)
			f[i][0] = f[j][0] + 1;
	DFOR(i, n, 1) FOR(j, i+1, n)
		if(a[i] > a[j] && f[i][1] < f[j][1] + 1)
			f[i][1] = f[j][1] + 1;
	FOR(i, 1, n) ans = max(ans, f[i][0]+f[i][1]-1);
	printf("%d\n", n - ans);
	
	return 0;
}
