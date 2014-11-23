#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
const int N = 1005, M = 1005;
int m, n, k, l, d, x[N], y[M], xx[N], yy[M], x1, y1, x2, y2;
int max(const int& a, const int& b) { return a > b ? a : b; }
int min(const int& a, const int& b) { return a < b ? a : b; }

struct cmp1 {bool operator() (const int& a, const int& b) { return x[a] > x[b]; }};
struct cmp2 {bool operator() (const int& a, const int& b) { return y[a] > y[b]; }};
int main() {
	scanf("%d%d%d%d%d", &m, &n, &k, &l, &d);
	int i;
	FOR(i, 1, d) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 == x2) y[min(y1, y2)]++;
		if(y1 == y2) x[min(x1, x2)]++;
	}
	FOR(i, 1, n) xx[i] = yy[i] = i;
	sort(xx+1, xx+1+n, cmp1()); sort(yy+1, yy+1+n, cmp2());
	FOR(i, 1, k) printf("%d ", xx[i]);
	printf("\n");
	FOR(i, 1, l) printf("%d ", yy[i]);
	return 0;
}