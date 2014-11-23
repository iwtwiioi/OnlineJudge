#include <cstdio>

using namespace std;
#define FOR(i, a, n) for(i = a; i <= (n); ++i)
#define NUM(j, i) ((((sum[i]-sum[j-1])%10)+10)%10)
#define oo (~(unsigned long long)(0)>>1)

const int N = 80, M = 12;
int i, j, k, l, n, m;
long long a[N], sum[N<<1], d[N][M][2], ans[2];
long long min(const long long& a, const long long& b) { return a < b ? a : b; }
long long max(const long long& a, const long long& b) { return a < b ? b : a; }

int main() {
	ans[0] = oo, ans[1] = oo+1;
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) { scanf("%lld", &a[i]); sum[i] = sum[i-1] + a[i]; }
	FOR(i, 1, n) sum[i+n] = sum[i+n-1] + a[i];
	FOR(l, 0, n-1) {
		FOR(i, 1, n) FOR(j, 1, m) d[i][j][0] = oo, d[i][j][1] = oo+1; //丧尽天良的初始化
		FOR(i, 1, n) d[i][1][0] = NUM(l+1, l+i), d[i][1][1] = NUM(l+1, l+i);
		FOR(k, 2, m) FOR(i, k, n) FOR(j, k-1, i-1)
			d[i][k][0] = min(d[i][k][0], d[j][k-1][0] * NUM(j+1+l, i+l)),
			d[i][k][1] = max(d[i][k][1], d[j][k-1][1] * NUM(j+1+l, i+l));
		ans[0] = min(ans[0], d[n][m][0]);
		ans[1] = max(ans[1], d[n][m][1]);
	}
	printf("%lld\n%lld\n", ans[0], ans[1]);
	return 0;
}
