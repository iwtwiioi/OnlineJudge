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

const int N=505, M=300005, dx[]={-1, 1, 0, 0}, dy[]={0, 0, 1, -1};
int mp[N][N], must[N][N], n, m, front, tail, vis[N][N], X, Y;
struct dat{ int x, y; }q[M];

void bfs(int D) {
	for1(i, 1, n) for1(j, 1, m) vis[i][j]=0;
	front=tail=0;
	q[tail].x=X, q[tail++].y=Y; vis[X][Y]=1;
	int x, y;
	while(tail!=front) {
		dat &t=q[front++]; if(front==M) front=0;
		x=t.x, y=t.y;
		rep(i, 4) {
			int fx=dx[i]+x, fy=dy[i]+y;
			if(fx<1 || fy<1 || fx>n || fy>m || vis[fx][fy] || abs(mp[fx][fy]-mp[x][y])>D) continue;
			vis[fx][fy]=1;
			q[tail].x=fx; q[tail++].y=fy; if(tail==M) tail=0;
		}
	}
}
bool check(int D) {
	bfs(D);
	for1(i, 1, n) for1(j, 1, m) if(must[i][j]==1 && !vis[i][j]) return false;
	return true;
}

int main() {
	int mx=0;
	read(n); read(m);
	for1(i, 1, n) for1(j, 1, m) read(mp[i][j]), mx=max(mx, mp[i][j]);
	for1(i, 1, n) for1(j, 1, m) {
		read(must[i][j]); if(must[i][j]==1) X=i, Y=j;
	}
	int l=0, r=mx;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	print(r+1);
	return 0;
}