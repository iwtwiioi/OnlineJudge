#include <cstdio>
using namespace std;
#define REP(i, a, n) for(i = a; i <= n; ++i)

const int MAXN = 45, MAXK = 8;
int n, m, i, j, k, c[MAXN][MAXN], d[MAXN][MAXK];
int max(const int& a, const int& b) { return a > b ? a : b; }

int main() {
	char str[MAXN];
	scanf("%d%d%s", &n, &m, str);
	REP(i, 1, n) REP(j, i, n) c[i][j] = c[i][j-1] * 10 + (str[j-1]-'0');
	REP(i, 1, n) d[i][0] = c[1][i];
	REP(k, 1, m) REP(i, k+1, n) REP(j, k, i-1) d[i][k] = max(d[i][k], d[j][k-1] * c[j+1][i]);
	printf("%d", d[n][m]);
	return 0;
}
