#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

struct aa {
	int d;
	bool f;
	bool operator< (const aa& a) const { return d>a.d; }
}a[5000];
int ans;

int main() {
	int n, m, i, r, c;
	scanf("%d%d", &n, &m);
	r=c=1; n--; m--;
	FOR(i, 1, n) { scanf("%d", &a[i].d); a[i].f=false; }
	FOR(i, n+1, n+m) { scanf("%d", &a[i].d); a[i].f=true; }
	sort(a+1, a+1+n+m);
	FOR(i, 1, n+m)
		if(a[i].f) ans+=a[i].d*r, c++;
		else ans+=a[i].d*c, r++;
	printf("%d\n", ans);
	
	return 0;
}

