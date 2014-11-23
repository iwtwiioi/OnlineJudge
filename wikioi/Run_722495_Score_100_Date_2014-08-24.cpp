#include <cstdio>
using namespace std;
const int N=60000, M=350000, oo=1000000000;
#define min(a,b) ((a)<(b)?(a):(b))
int ihead[N], inext[M], from[M], to[M], cap[M], cnt=1;
int cur[N], gap[N], d[N], p[N];
 
int isap(int s, int t, int n) {
    int i, maxflow=0, f, u;
    for(i=0; i<=n; ++i) cur[i]=ihead[i];
    gap[0]=n; u=s;
    while(d[s]<n) {
        for(i=cur[u]; i; i=inext[i]) if(d[to[i]]+1==d[u] && cap[i]) break;
        if(i) {
            cur[u]=i; p[to[i]]=i; u=to[i];
            if(u==t) {
                for(f=oo; u!=s; u=from[p[u]]) f=min(f, cap[p[u]]);
                for(u=t; u!=s; u=from[p[u]]) cap[p[u]]-=f, cap[p[u]^1]+=f;
                maxflow+=f;
            }
        }
        else {
            if(!(--gap[d[u]])) break;
            d[u]=n;
            for(i=ihead[u]; i; i=inext[i]) if(cap[i] && d[u]>d[to[i]]+1)
                d[u]=d[to[i]]+1, cur[u]=i;
            ++gap[d[u]]; if(u!=s) u=from[p[u]];
        }
    }
    return maxflow;
}
 
void add(int u, int v, int c) {
    inext[++cnt]=ihead[u]; ihead[u]=cnt; from[cnt]=u; to[cnt]=v; cap[cnt]=c;
    inext[++cnt]=ihead[v]; ihead[v]=cnt; from[cnt]=v; to[cnt]=u; cap[cnt]=0;
}
 
int main() {
    int n, m, sum=0;
    scanf("%d%d", &n, &m);
    int i, a, b, c;
    for(i=1; i<=n; ++i) {
        scanf("%d", &c);
        add(m+i, n+m+1, c);
    }
    for(i=1; i<=m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        sum+=c;
        add(i, m+a, oo); add(i, m+b, oo);
        add(0, i, c);
    }
    printf("%d\n", sum-isap(0, n+m+1, n+m+2));
    return 0;
}