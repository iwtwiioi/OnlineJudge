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
  
const int N=20005, Q=N*10, oo=~0u>>2;
int q[Q], front, tail, d[N], vis[N], ihead[N], cnt, n, m;
struct ED { int to, next; }e[Q];
void add(int u, int v) {
    e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
    e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}
void spfa() {
    q[tail++]=1;
    for1(i, 2, n) d[i]=oo;
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
}
  
int main() {
    read(n); read(m);
    for1(i, 1, m) {
        int u=getint(), v=getint();
        add(u, v);
    }
    spfa();
    int mx=0, ans=0, id=oo;
    for1(i, 1, n) mx=max(d[i], mx);
    for1(i, 1, n) if(d[i]==mx) { ++ans; id=min(i, id); }
    printf("%d %d %d", id, mx, ans);
    return 0;
}