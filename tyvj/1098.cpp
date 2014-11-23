#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N=5050, S=55, oo=1000000000;
int f[N], t[N], c[N], n, s;

int main() {
	int i, j;
	scanf("%d%d", &n, &s);
	FOR(i, 1, n) {
		scanf("%d%d", &t[i], &c[i]);
		t[i]+=t[i-1]; c[i]+=c[i-1];
	}
	FOR(i, 1, n) f[i]=oo;
	FOR(i, 1, n) {
		FOR(j, 0, i-1) {
			f[i]=min(f[i], f[j]+s*(c[n]-c[j])+t[i]*(c[i]-c[j]));
		}
	}
	printf("%d\n", f[n]);
	return 0;
}

