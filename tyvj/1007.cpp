#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
const int N = 1005, M = 1005;
int m, n, k, l, d, x[N], y[M], xx[N], yy[M], an[N], bn[M], ix1, iy1, ix2, iy2;
int max(const int& a, const int& b) { return a > b ? a : b; }
int min(const int& a, const int& b) { return a < b ? a : b; }

struct cmp1 {bool operator() (const int& a, const int& b) { return x[a] > x[b]; }};
struct cmp2 {bool operator() (const int& a, const int& b) { return y[a] > y[b]; }};
int main() {
	scanf("%d%d%d%d%d", &m, &n, &k, &l, &d);
	int i;
	FOR(i, 1, d) {
		scanf("%d%d%d%d", &ix1, &iy1, &ix2, &iy2);
		if(ix1 == ix2) y[min(iy1, iy2)]++;
		if(iy1 == iy2) x[min(ix1, ix2)]++;
	}
	FOR(i, 1, n) xx[i] = yy[i] = i;
	sort(xx+1, xx+1+n, cmp1()); sort(yy+1, yy+1+n, cmp2());
	FOR(i, 1, k) an[xx[i]] = 1; FOR(i, 1, l) bn[yy[i]] = 1;
	FOR(i, 1, n) if(an[i]) printf("%d ", i);
	printf("\n");
	FOR(i, 1, n) if(bn[i]) printf("%d ", i);
	return 0;
}
