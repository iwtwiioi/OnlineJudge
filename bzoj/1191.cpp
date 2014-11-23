#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define for1(i,a,n) for(i=a;i<=n;++i)
#define for2(i,a,n) for(i=a;i<n;++i)
#define for3(i,a,n) for(i=a;i>=n;--i)
#define for4(i,a,n) for(i=a;i>n;--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) a=getnum()
#define print(a) printf("%d", a)
inline int getnum() { int ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }

const int N=2405, M=N*N;
int ihead[N], inext[M], to[M], cnt;
int x[N], y[N], visy[N];

inline void add(const int &u, const int &v) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v;
	inext[++cnt]=ihead[v]; ihead[v]=cnt; to[cnt]=u;
}

bool ifind(const int &u) {
	for(int i=ihead[u], v; i; i=inext[i]) if(!visy[v=to[i]]) {
		visy[v]=1;
		if(!y[v] || ifind(y[v])) {
			y[v]=u;
			return true;
		}
	}
	return false;
}

int main() {
	int n, m, ans=0;
	read(n); read(m);
	int i;
	for1(i, 1, m) {
		add(i, getnum()+1+m);
		add(i, getnum()+1+m);
	}
	for1(i, 1, m) {
		CC(visy, 0);
		if(ifind(i)) ans++;
		else break; //坑爹，“顺利进入下一题”，自己yy吧
	}
	printf("%d\n", ans);
	return 0;
}

