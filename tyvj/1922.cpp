#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) scanf("%d", &a)
#define print(a) printf("%d", a)
#define num(i, j) ((i-1)*n+j)
#define who(i, j) (i%2==j%2)
#define arr(a, n) for1(i, 1, n) { for1(j, 1, n) print(a[i][j]); printf("\n"); }
#define arr2(a, n) for1(i, 1, n) print(a[i]); printf("\n")
inline int getnum() { int ret=0; char c; int k=1; for(c=getchar(); c<'0' || c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return k*ret; }
 
const int fx[8]={1, 1, 2, 2, -1, -1, -2, -2}, fy[8]={-2, 2, -1, 1, -2, 2, -1, 1};
const int N=205*205, M=N*8+100;
int ihead[N], cnt, x[N], cont, ly[N], n, m, mm[205][205];
struct dd { int next, to; }e[M];
bool vis[N];
 
inline void add(const int &u, const int &v) {
    e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
}
 
bool ifind(const int &x) {
    vis[x]=true; int y;
    for(int i=ihead[x]; i; i=e[i].next) if(!vis[y=e[i].to]) {
        vis[y]=true;
        if(!ly[y] || ifind(ly[y])) {
            ly[y]=x;
            return true;
        }
    }
    return false;
}
 
int main() {
    read(n); read(m);
    int a, b, nx, ny, ans=0;
    rep(i, m) read(a), read(b), mm[a][b]=1;
    for1(i, 1, n) for1(j, 1, n) if(!mm[i][j] && who(i, j)) {
        rep(k, 8) {
            nx=i+fx[k], ny=j+fy[k];
            if(mm[nx][ny] || nx<1 || nx>n || ny<1 || ny>n) continue;
            add(num(i, j), num(nx, ny));
        }
        x[++cont]=num(i, j);
    }
    for1(i, 1, cont) {
        CC(vis, 0);
        if(ifind(x[i])) ans++;
    }
    print(n*n-ans-m);
     
    return 0;
}
