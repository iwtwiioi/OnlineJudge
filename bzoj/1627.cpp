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

const int N=1000005, dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
struct ND { int d, x, y; }q[N];
int tail, front, vis[1005][1005], mp[1005][1005];
int main() {
	int X, Y, x, y, fx, fy;
	read(X); read(Y); int n=getint(); X+=500; Y+=500;
	while(n--) {
		read(x); read(y); mp[x+500][y+500]=1;
	}
	ND t={0, 500, 500};
	q[tail++]=t;
	while(front!=tail) {
		t=q[front++]; if(front==N) front=0;
		x=t.x; y=t.y;
		if(x==X && y==Y) { printf("%d\n", t.d); return 0; }
		rep(i, 4) {
			fx=dx[i]+x; fy=dy[i]+y;
			if(fx<0 || fy<0 || fx>1000 || fy>1000 || mp[fx][fy] || vis[fx][fy]) continue;
			vis[fx][fy]=1;
			q[tail].x=fx; q[tail].y=fy; q[tail++].d=t.d+1;
			if(tail==N) tail=0;
		}
	}
	return 0;
}

