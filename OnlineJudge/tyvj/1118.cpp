#include <cstdio>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
int main() {
	int a, b, i, ans = 1;
	scanf("%d%d", &a, &b);
	FOR(i, 1, b) ans = (a*ans)%1012;
	printf("%d", ans);
	return 0;
}
