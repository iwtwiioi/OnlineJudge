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

const int N=1105, oo=~0u>>2, Q=N*N, dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
int mp[N][N], n, m, d[N][N], X, Y, XX, YY, front, tail;
struct dat { int x, y; }q[Q];
struct HS { int x[2], y[2]; }hs[51];

void bfs() {
	q[tail].x=X, q[tail++].y=Y;
	for1(i, 1, n) for1(j, 1, m) d[i][j]=oo;
	d[X][Y]=0;
	while(front!=tail) {
		dat &t=q[front++]; if(front==Q) front=0;
		int x=t.x, y=t.y;
		if(XX==x && YY==y) continue;
		rep(i, 4) {
			int fx=dx[i]+x, fy=dy[i]+y;
			if(fx<1 || fy<1 || fx>n || fy>m || mp[fx][fy]==1) continue;
			if(mp[fx][fy]>=4) {
				int h=mp[fx][fy], pos=(hs[h].x[0]==fx && hs[h].y[0]==fy);
				fx=hs[h].x[pos], fy=hs[h].y[pos];
			}
			if(d[fx][fy]>d[x][y]+1) {
				dat &t2=q[tail++]; if(tail==Q) tail=0;
				t2.x=fx, t2.y=fy; d[fx][fy]=d[x][y]+1;
			}
		}
	}
}

int main() {
	read(n); read(m);
	for1(i, 1, 50) CC(hs[i].x, 0), CC(hs[i].y, 0);
	for1(i, 1, n) for1(j, 1, m) {
		char ch=getchar(); while(ch=='\n' || ch=='\0') ch=getchar();
		if(ch=='#') mp[i][j]=1;
		else if(ch=='=') mp[i][j]=2, XX=i, YY=j;
		else if(ch=='@') mp[i][j]=3, X=i, Y=j;
		else if(ch>='A'&&ch<='Z') {
			int t=4+ch-'A', pos=(hs[t].x[0]!=0);
			hs[t].x[pos]=i; hs[t].y[pos]=j;
			mp[i][j]=t;
		}
	}
	bfs();
	print(d[XX][YY]);
	return 0;
}