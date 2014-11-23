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
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << #x << " = " << x << endl
#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=305, fx[]={-1, 1, 0, 0}, fy[]={0, 0, -1, 1}, oo=~0u>>1, Q=95000;
int mp[N][N], front, tail, n, vis[N][N];
struct ND { int x, y, d; }q[Q];
int main() {
	read(n);
	int x, y, z, dx, dy;
	for1(i, 1, N-1) for1(j, 1, N-1) mp[i][j]=oo;
	for1(i, 1, n) {
		read(x); read(y); read(z);
		++x; ++y;
		mp[x][y]=min(mp[x][y], z);
		rep(j, 4) {
			dx=x+fx[j]; dy=y+fy[j];
			mp[dx][dy]=min(mp[dx][dy], z);
		}
	}
	ND t={1, 1, 0};
	q[tail++]=t;
	while(front!=tail) {
		t=q[front++]; if(front==Q) front=0;
		x=t.x; y=t.y; z=t.d;
		if(mp[x][y]==oo) { printf("%d\n", z); return 0; }
		rep(i, 4) {
			dx=x+fx[i]; dy=y+fy[i];
			if(dx<1 || dy<1 || mp[dx][dy]<=z+1 || vis[dx][dy]) continue;
			if(mp[dx][dy]==oo) { printf("%d\n", z+1); return 0; }
			vis[dx][dy]=1;
			q[tail].x=dx; q[tail].y=dy; q[tail++].d=z+1;
			if(tail==Q) tail=0;
		}
	}
	puts("-1");
	return 0;
}

