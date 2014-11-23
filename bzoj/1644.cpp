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

const int N=105, Q=N*N*N*3, dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};
int mp[N][N], front, tail, n, f[N][N][4];
struct dat { int x, y; }q[Q];
int main() {
	read(n);
	char s[105];
	int x, y, xx, yy;
	for1(i, 1, n) {
		scanf("%s", s+1);
		for1(j, 1, n) {
			if(s[j]=='x') mp[i][j]=1;
			else if(s[j]=='B') mp[i][j]=3, xx=i, yy=j;
			else if(s[j]=='A') mp[i][j]=2, x=i, y=j;
		}
	}
	CC(f, 0x7f);
	int ans=~0u>>1;
	q[tail].x=x, q[tail++].y=y;
	rep(i, 4) f[x][y][i]=0;
	while(front!=tail) {
		dat &t=q[front++]; if(front==Q) front=0;
		x=t.x, y=t.y;
		rep(i, 4) {
			int fx=dx[i]+x, fy=dy[i]+y;
			if(fx<1 || fy<1 || fx>n || fy>n || mp[fx][fy]==1) continue;
			rep(j, 4) {
				bool flag=0;
				if(i==j && f[fx][fy][i]>f[x][y][i]) {
					f[fx][fy][i]=f[x][y][i];
					flag=1;
				}
				if(i!=j && f[fx][fy][i]>f[x][y][j]+1) {
					f[fx][fy][i]=f[x][y][j]+1;
					flag=1;
				}
				if(flag) {
					dat &t2=q[tail++]; if(tail==Q) tail=0;
					t2.x=fx; t2.y=fy;
				}
			}
		}
	}
	rep(i, 4) ans=min(f[xx][yy][i], ans);
	print(ans);
	return 0;
}

