#include <cstdio>
#include <cstring>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
const int maxn=5005;
int p[maxn];
int find(int x) { if(x==p[x]) return x; return p[x]=find(p[x]); }

int main() {
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	int i, a, b;
	FOR(i, 1, n) p[i]=i;
	FOR(i, 1, m) {
		scanf("%d%d", &a, &b);
		p[find(b)]=find(a);
	}
	FOR(i, 1, t) {
		scanf("%d%d", &a, &b);
		if(find(a)==find(b)) printf("Yes\n");
		else  printf("No\n");
	}
	return 0;
}

