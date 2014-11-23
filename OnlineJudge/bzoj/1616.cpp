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

const int N=105, fx[]={-1, 1, 0, 0}, fy[]={0, 0, -1, 1}, Q=2000005;
int mp[N][N], front, tail, n, m, T, R, C;
struct ND { int x, y, d; }q[Q];
int main() {
	read(n); read(m); read(T);
	int x, y, z, dx, dy;
	char st[105];
	for1(i, 1, n) {
		scanf("%s", st);
		for1(j, 1, m) if(st[j-1]!='.') mp[i][j]=1;
	}
	read(x); read(y); read(R); read(C);
	ND t={x, y, 0};
	q[tail++]=t;
	long long ans=0;
	while(front!=tail) {
		t=q[front++]; if(front==Q) front=0;
		x=t.x; y=t.y; z=t.d;
		if(x==R && y==C && z==T) ++ans;
		if(z==T) continue;
		rep(i, 4) {
			dx=x+fx[i]; dy=y+fy[i];
			if(dx<1 || dy<1 || mp[dx][dy]) continue;
			q[tail].x=dx; q[tail].y=dy; q[tail++].d=z+1;
			if(tail==Q) tail=0;
		}
	}
	printf("%lld", ans);
	return 0;
}
