#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int maxn=405;
bool f[40050];
int h[maxn], c[maxn], a[maxn], ran[maxn];
bool cmp(const int& _a, const int& _b) { return a[_a]<a[_b]; }

int main() {
	int n, i, j, k, l;
	scanf("%d", &n);
	f[0]=true;
	FOR(i, 1, n) { scanf("%d%d%d", &h[i], &a[i], &c[i]); ran[i]=i; }
	sort(ran+1, ran+1+n, cmp);
	FOR(l, 1, n) {
		k=ran[l];
		FOR(j, 1, c[k]) for(i=a[k]; i>=h[k]; --i)
			if(f[i-h[k]]) f[i]=true;
	}
	for(i=a[ran[n]]; i>=0; --i) if(f[i]) break;
	printf("%d\n", i);
	return 0;
}

