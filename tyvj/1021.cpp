#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
int n, a[10002];
long long ans;
int main() {
	scanf("%d", &n);
	int i;
	FOR(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	FOR(i, 1, n-1) ans += (long long)i*(n-i)*(long long)(a[i+1]-a[i]);
	ans <<= 1;
	printf("%lld\n", ans);
	return 0;
}
