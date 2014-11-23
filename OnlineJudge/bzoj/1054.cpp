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

const int N=1000000, fx[]={-1, 1, 0, 0}, fy[]={0, 0, -1, 1};
inline const bool check(const int &x, const int &y) { if(x<0 || x>3 || y<0 || y>3) return 0; return 1; }
struct Matrix {
	bool m[4][4];
	int d;
}q[N], ini;
int front, tail, ans, vis[100000];
inline int hash(const Matrix &x) {
	int k=1, ret=0;
	rep(i, 4) rep(j, 4) { ret+=k*x.m[i][j]; k<<=1; }
	return ret;
}

int main() {
	char c[10];
	tail=1;
	rep(i, 4) {
		scanf("%s", c);
		rep(j, 4)
			q[0].m[i][j]=c[j]-'0';
	}
	rep(i, 4) {
		scanf("%s", c);
		rep(j, 4)
			ini.m[i][j]=c[j]-'0';
	}
	int hs;
	ans=hash(ini);
	hs=hash(q[0]);
	if(ans==hs) { printf("0"); return 0; }
	vis[hs]=1;
	while(front!=tail) {
		Matrix &x=q[front++]; if(front==N) front=0;
		rep(i, 4) rep(j, 4) if(x.m[i][j]) {
			rep(k, 4) {
				int px=fx[k]+i, py=fy[k]+j;
				if(check(px, py) && x.m[px][py]==0) {
					q[tail]=x; ++q[tail].d;
					swap(q[tail].m[i][j], q[tail].m[px][py]);
					hs=hash(q[tail]);
					if(hs==ans) {
						printf("%d", q[tail].d);
						return 0;
					}
					if(vis[hs]) continue;
					vis[hs]=1;
					++tail; if(tail==N) tail=0;
				}
			}
		}
	}
	return 0;
}

