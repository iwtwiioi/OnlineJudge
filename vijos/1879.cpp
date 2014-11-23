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
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr(a, n, m) for1(aaa, 1, n) { for1(bbb, 1, m) cout << a[aaa][bbb] << '\t'; cout << endl; }
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
#define error(x) (!(x)?puts("error"):0)

const int N=22, Q=5000000, dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
int front, tail, n, m, l, mp[N][N], ALL;
bool vis[N][N][18000];
struct dat { int x, y, d, f; }q[Q];
bool check(int f, int x) {
	f=(f<<2)|x;
	int s1=0, s2=0;
	rep(i, l) {
		int now=(f>>(i<<1))&3;
		s1+=dx[now];
		s2+=dy[now];
		if(s1==0 && s2==0) return false;
	}
	return true;
}
void bfs() {
	front=tail=0; ++tail;
	vis[q[0].x][q[0].y][q[0].f]=1;
	while(front!=tail) {
		dat &t=q[front++]; if(front==Q) front=0;
		int x=t.x, y=t.y, dis=t.d;
		if(x==1 && y==1) { printf("%d\n", dis); return; }
		rep(i, 4) {
			int fx=dx[i]+x, fy=dy[i]+y;
			if(fx<1 || fy<1 || fx>n || fy>m || mp[fx][fy] || vis[fx][fy][((t.f<<2)|i)&ALL]) continue;
			if(!check(t.f, i)) continue;
			dat &t2=q[tail++]; if(tail==Q) tail=0;
			t2.x=fx;
			t2.y=fy;
			t2.d=dis+1;
			t2.f=((t.f<<2)|i)&ALL;
			vis[fx][fy][t2.f]=1;
		}
	}
	puts("-1");
}
int main() {
	int cs=0;
	while(~scanf("%d%d%d", &n, &m, &l) && !(n==0 && m==0 && l==0)) {
		printf("Case %d: ", ++cs);

		CC(mp, 0);
		CC(vis, 0);
		q[0].f=0;
		q[0].d=0;
		ALL=(1<<((l-1)<<1))-1;

		int nx=getint(), ny=getint();
		q[0].x=nx, q[0].y=ny;
		int &f=q[0].f;
		rep(i, l-1) {
			int x=getint(), y=getint();
			if(x==nx-1) f|=(1<<(i<<1));
			else if(x==nx+1) f|=(0<<(i<<1));
			else if(y==ny-1) f|=(3<<(i<<1));
			else if(y==ny+1) f|=(2<<(i<<1));
			nx=x; ny=y;
		}
		int k=getint();
		while(k--) { int x=getint(), y=getint(); mp[x][y]=1; } 
		bfs();
	}
	return 0;
}