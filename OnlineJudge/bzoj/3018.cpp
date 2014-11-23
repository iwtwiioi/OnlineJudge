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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i]; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
 
const int N=55, M=10005, dx[]={-1, 1, 0, 0}, dy[]={0, 0, 1, -1};
int mp[N][N], n, front, tail, f[N][N], A, B;
struct dat{ int x, y; }q[M];
 
void bfs() {
	CC(f, 0);
    front=tail=0;
    q[tail].x=1, q[tail++].y=1;
    int x, y;
    while(tail!=front) {
        dat &t=q[front++]; if(front==M) front=0;
        x=t.x, y=t.y;
        rep(i, 4) {
            int fx=dx[i]+x, fy=dy[i]+y;
            if(fx<1 || fy<1 || fx>n || fy>n || f[fx][fy]>f[x][y]+(mp[x][y]==mp[fx][fy]?A:B)) continue;
   			f[fx][fy]=f[x][y]+(mp[x][y]==mp[fx][fy]?A:B);
            q[tail].x=fx; q[tail++].y=fy; if(tail==M) tail=0;
        }
    }
}
int main() {
    read(n); read(A); read(B);
    for1(i, 1, n) for1(j, 1, n) {
    	char ch=getchar(); while(ch!='('&&ch!=')') ch=getchar();
    	mp[i][j]=ch;
    }
    bfs();
    print(f[n][n]);
    return 0;
}