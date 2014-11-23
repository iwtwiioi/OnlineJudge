#include <cstdio>
#include <cstring>
using namespace std;
#define CC(a, b) memset(a, b, sizeof(a))
#define min(a,b) ((a)<(b)?(a):(b))
const int N=2100, M=1000001, oo=1000000000;
int ihead[N], inext[M], from[M], to[M], cap[M], cost[M], cnt=1;
int d[N], p[N];
bool vis[N];
int q[N], front, tail;

void add(int u, int v, int c, int m) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; from[cnt]=u; to[cnt]=v; cap[cnt]=c; cost[cnt]=m;
	inext[++cnt]=ihead[v]; ihead[v]=cnt; from[cnt]=v; to[cnt]=u; cap[cnt]=0; cost[cnt]=-m;
}

bool spfa(const int &s, const int &t, const int &n) {
	int i, u;
	for(i=0; i<=n; ++i) d[i]=oo, vis[i]=0;
	d[s]=front=tail=0; vis[s]=1;
	q[tail++]=s;
	while(front!=tail) {
		u=q[front++]; if(front==2001) front=0;
		for(i=ihead[u]; i; i=inext[i]) if(cap[i] && d[to[i]]>d[u]+cost[i]) {
			d[to[i]]=d[u]+cost[i];
			p[to[i]]=i;
			if(!vis[to[i]]) {
				vis[to[i]]=1;
				q[tail++]=to[i]; if(tail==2001) tail=0;
			}
		}
		vis[u]=0;
	}
	return d[t]!=oo;
}

int mincost(const int &s, const int &t, const int &n) {
	int ret=0, f, u;
	while(spfa(s, t, n)) {
		for(f=oo, u=t; u!=s; u=from[p[u]]) f=min(f, cap[p[u]]);
		for(u=t; u!=s; u=from[p[u]]) cap[p[u]]-=f, cap[p[u]^1]+=f;
		ret+=d[t]*f;
	}
	return ret;
}

int main() {
	int n, a, b, f, fa, fb, i, r;
	scanf("%d%d%d%d%d%d", &n, &a, &b, &f, &fa, &fb);
	int s=0, t=(n<<1)+1;
	for(i=1; i<=n; ++i) {
		if(i+1<=n) add(i, i+1, oo, 0);
		if(i+a+1<=n) add(i, n+i+a+1, oo, fa);
		if(i+b+1<=n) add(i, n+i+b+1, oo, fb);
		add(0, n+i, oo, f);
	}
	for(i=1; i<=n; ++i) {
		scanf("%d", &r);
		add(s, i, r, 0);
		add(n+i, t, r, 0);
	}
	printf("%d\n", mincost(s, t, t+1));
	return 0;
}

