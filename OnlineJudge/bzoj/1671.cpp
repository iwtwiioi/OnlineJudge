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

const int N=1005, Q=N*N, dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
struct dat { int x, y; } q[Q];
int front, tail, d[N][N], d2[N][N], mp[N][N], n, m, xx, yy, X, Y, ans=~0u>>1;
void bfs1() {
	q[0].x=xx, q[0].y=yy; ++tail;
	CC(d, 0x7f);
	d[xx][yy]=0;
	while(tail!=front) {
		dat &t=q[front++]; if(front==Q) front=0;
		int x=t.x, y=t.y;
		rep(i, 4) {
			int fx=dx[i]+x, fy=dy[i]+y;
			if(fx<1 || fy<1 || fx>n || fy>m || mp[fx][fy]==1) continue; 
			if(d[fx][fy]>d[x][y]+1) {
				d[fx][fy]=d[x][y]+1;
				q[tail].x=fx; q[tail++].y=fy; if(tail==Q) tail=0;
			}
		}
	}
}
void bfs2() {
	q[0].x=X, q[0].y=Y; front=tail=0; ++tail;
	CC(d2, 0x7f);
	d2[X][Y]=0;
	while(tail!=front) {
		dat &t=q[front++]; if(front==Q) front=0;
		int x=t.x, y=t.y;
		if(mp[x][y]==4) { ans=min(d2[x][y]+d[x][y], ans); continue; }
		rep(i, 4) {
			int fx=dx[i]+x, fy=dy[i]+y;
			if(fx<1 || fy<1 || fx>n || fy>m || mp[fx][fy]==1 || mp[fx][fy]==3) continue; 
			if(d2[fx][fy]>d2[x][y]+1) {
				d2[fx][fy]=d2[x][y]+1;
				q[tail].x=fx; q[tail++].y=fy; if(tail==Q) tail=0;
			}
		}
	}
}

int main() {
	read(m); read(n);
	for1(i, 1, n) for1(j, 1, m) {
		char ch=getchar();
		for(; ch<'0'||ch>'9'; ch=getchar());
		mp[i][j]=ch-'0';
		if(ch=='2') X=i, Y=j;
		if(ch=='3') xx=i, yy=j;
	}
	bfs1();
	bfs2();
	print(ans);
	return 0;
}

