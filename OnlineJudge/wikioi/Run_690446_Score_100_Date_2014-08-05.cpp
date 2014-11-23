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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
inline int getnum() { int ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }

const int N=10005;
int n, m, a[105][105], imap[105][105], cnt;
int ihead[N], inext[N*4], to[N*4];
bool visy[N];
int ly[N], x[N], cntx;
inline void add(const int &u, const int &v) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v;
}

bool ifind(const int &u) {
	int v;
	for(int i=ihead[u]; i; i=inext[i]) if(!visy[v=to[i]]) {
		visy[v]=true;
		if(!ly[v] || ifind(ly[v])) {
			ly[v]=u;
			return true;
		}
	}
	return false;
}

int main() {
	read(n); read(m);
	int k=getnum();
	for1(i, 1, k) a[getnum()][getnum()]=1;
	int last;
	int u;
	for1(i, 1, n) {
		last=i;
		for1(j, 1, m) {
			if(!a[i][j] && (last%2))  {
				u=(i-1)*m+j;
				if(i>1 && !a[i-1][j]) add(u, u-m);
				if(i<n && !a[i+1][j]) add(u, u+m);
				if(j>1 && !a[i][j-1]) add(u, u-1);
				if(j<m && !a[i][j+1]) add(u, u+1);
				x[++cntx]=u;
			}
			++last;
		}
	}
	int ans=0;
	for1(i, 1, cntx) {
		CC(visy, 0);
		if(ifind(x[i])) ++ans;
	}
	print(ans);
	return 0;
}
