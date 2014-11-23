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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j] << '\t'; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=35, Q=10000, dx[]={-1, -2, -2, -1, 1, 2, 2, 1}, dy[]={-2, -1, 1, 2, 2, 1, -1, -2};
int mp[N][N], f[N][N], d[N][N], vis[N][N], n, m, X, Y, XX, YY, front, tail;
struct dat { int x, y; }q[Q];
long long p[N][N];

void bfs1() {
    front=tail=0;
    q[tail].x=X, q[tail].y=Y; ++tail;
    CC(f, 0x3f); CC(d, 0x3f); f[X][Y]=d[X][Y]=0; vis[X][Y]=p[X][Y]=1;
    while(front!=tail) {
        dat &t=q[front++]; if(front==Q) front=0;
        int x=t.x, y=t.y; vis[x][y]=0;
        if(x==XX && y==YY) continue;
        rep(i, 8) {
            int fx=dx[i]+x, fy=dy[i]+y;
            if(fx<1 || fy<1 || fx>n || fy>m || mp[fx][fy]==2) continue;
            dat &t2=q[tail];
            int add=mp[fx][fy]==0;
            if(f[fx][fy]>f[x][y]+add) {
                f[fx][fy]=f[x][y]+add;
                d[fx][fy]=d[x][y]+1;
                p[fx][fy]=p[x][y];
                if(!vis[fx][fy]) t2.x=fx, t2.y=fy, vis[fx][fy]=1;; if(++tail==Q) tail=0;
            }
            else if(f[fx][fy]==f[x][y]+add && d[fx][fy]>d[x][y]+1) {
                d[fx][fy]=d[x][y]+1;
                p[fx][fy]=p[x][y];
                if(!vis[fx][fy]) t2.x=fx, t2.y=fy, vis[fx][fy]=1;; if(++tail==Q) tail=0;
            }
            else if(f[fx][fy]==f[x][y]+add && d[fx][fy]==d[x][y]+1) {
                p[fx][fy]+=p[x][y];
                if(!vis[fx][fy]) t2.x=fx, t2.y=fy, vis[fx][fy]=1;; if(++tail==Q) tail=0;
            }
        }
    }
}
int main() {
    read(n); read(m);
    for1(i, 1, n) for1(j, 1, m) {
        int t=getint(); mp[i][j]=t;
        if(t==3) X=i, Y=j; else if(t==4) XX=i, YY=j;
    }
    bfs1();
    if(f[XX][YY]==0x3f3f3f3f) puts("-1");
    else printf("%d\n%d\n%lld\n", f[XX][YY], d[XX][YY], p[XX][YY]);
    return 0;
}