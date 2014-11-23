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
 
const int N=1005, Q=N*100, oo=~0u>>2;
int q[Q], front, tail, d[N], vis[N], ihead[N], cnt, n, x;
struct ED { int to, next; }e[Q];
void add(int u, int v) {
    e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
}
int spfa() {
    q[tail++]=1;
    for1(i, 2, 1005) d[i]=oo;
    vis[1]=1;
    while(front!=tail) {
        int v, u=q[front++]; if(front==Q) front=0; vis[u]=0;
        for(int i=ihead[u]; i; i=e[i].next) if(d[v=e[i].to]>d[u]+1) {
            d[v]=d[u]+1;
            if(!vis[v]) {
                vis[v]=1;
                q[tail++]=v; if(tail==Q) tail=0;
            }
        }
    }
    return d[x];
}
 
int main() {
    read(n); read(x);
    for1(i, 1, n) {
        int u=getint(), v=getint();
        add(u, v);
    }
    int ans=spfa();
    if(ans==oo) puts("-1");
    else print(ans+1);
    return 0;
}