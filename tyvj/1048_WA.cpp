#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)
const int N=2000;
int a[N], b[N], n, i, x, y, ans;
int main() {
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &a[i]);
	FOR(i, 1, n) scanf("%d", &b[i]);
	int l1, l2, r1, r2;
	l1=l2=1; r1=r2=n;
	while(l1!=r1) {
		while(a[l1]>b[l2]) ans+=200, l1++, l2++;
		if(a[l1]<b[r2]) ans-=200, l1++, r2--;
		while(a[r1]>b[r2]) ans+=200, r1--, r2--;
	}
	if(a[l1]>b[l2]) ans+=200, l1++, l2++;
	else if(a[l1]<b[r2]) ans-=200, l1++, r2--;
	printf("%d\n", ans);
	return 0;
}
