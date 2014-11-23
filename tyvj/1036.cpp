#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
int num[200005], n;
int main() {
	scanf("%d", &n);
	int i, cnt, l, t;
	FOR(i, 1, n) scanf("%d", &num[i]);
	sort(num+1, num+1+n);
	cnt = 1; l = t = num[1];
	FOR(i, 2, n) {
		t = num[i];
		if(t != l) { printf("%d %d\n", l, cnt); cnt = 1; l = t; }
		else cnt++;
	}
	printf("%d %d\n", l, cnt);
	return 0;
}
