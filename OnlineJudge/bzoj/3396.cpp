#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << #x << " = " << x << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
 
const int N=105, Q=N*100, oo=~0u>>1;
int ihead[N+10], cnt=1, n, gap[N+10], d[N+10], cur[N+10], p[N+10];
struct ED { int from, to, next, cap; }e[Q];
void add(int u, int v, int c) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v; e[cnt].from=u; e[cnt].cap=c;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u; e[cnt].from=v; e[cnt].cap=0;
}
int get() {
	int t=0;
	char ch=getchar(); while(!(ch>='A'&&ch<='Z')&&!(ch>='a'&&ch<='z')) ch=getchar();
	if(ch>='A'&&ch<='Z') t=27+ch-'A';
	else t=ch-'a'+1;
    return t;
}

int isap() {
    for1(i, 1, N) cur[i]=ihead[i];
    gap[0]=N;
    int s=27, t=27+'Z'-'A', u=s, i, flow=0, f;
    while(d[s]<N) {
        for(i=cur[u]; i; i=e[i].next) if(d[u]==d[e[i].to]+1 && e[i].cap) break;
        if(i) {
            p[e[i].to]=i; cur[u]=i; u=e[i].to;
            if(u==t) {
                for(f=oo; u!=s; u=e[p[u]].from) f=min(f, e[p[u]].cap);
                for(u=t; u!=s; u=e[p[u]].from) e[p[u]].cap-=f, e[p[u]^1].cap+=f;
                flow+=f;
            }
        }
        else {
            if(!(--gap[d[u]])) break;
            d[u]=N;
            cur[u]=ihead[u];
            for(i=ihead[u]; i; i=e[i].next) if(e[i].cap && d[u]>d[e[i].to]+1) d[u]=d[e[i].to]+1;
            ++gap[d[u]];
            if(u!=s) u=e[p[u]].from;
        }
    }
    return flow;
}
 
int main() {
	read(n);
	for1(i, 1, n) {
        int u=get(), v=get(), c=getint();
		add(u, v, c);
	}
	int ans=isap();
	if(ans==oo) puts("-1");
	else print(ans);
	return 0;
}