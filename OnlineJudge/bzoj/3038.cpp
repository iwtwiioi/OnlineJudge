#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
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
#define lc (rt << 1)
#define rc (rt << 1|1)
#define lson l, m, lc
#define rson m+1, r, rc
#define MID (l+r)>>1

inline long long getnum() { long long ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }

const int N=500001;
int L, R;
long long sum[N];
bool flag[N];

inline void pushup(const int &rt) { sum[rt]=sum[lc]+sum[rc]; flag[rt]=flag[lc]&flag[rc]; }

void build(const int &l, const int &r, const int &rt) {
	if(l==r) {
		sum[rt]=getnum();
		if(sum[rt]==1||sum[rt]==0) flag[rt]=true;
		return;
	}
	int m=MID;
	build(lson); build(rson);
	pushup(rt);
}

void update(const int &l, const int &r, const int &rt) {
	if(flag[rt]) return;
	if(l==r) {
		sum[rt]=(long long)sqrt(sum[rt]);
		if(sum[rt]==1||sum[rt]==0) flag[rt]=true;
		return;
	}
	int m=MID;
	if(L<=m) update(lson);
	if(m<R) update(rson);
	pushup(rt);
}

long long query(const int &l, const int &r, const int &rt) {
	if(L<=l && r<=R) return sum[rt];
	int m=MID;
	long long ret=0;
	if(L<=m) ret+=query(lson);
	if(m<R) ret+=query(rson);
	return ret;
}

int main() {
	int n=getnum();
	build(1, n, 1);
	L=1, R=n;
	int m=getnum(), c;
	while(m--) {
		c=getnum();
		read(L); read(R);
		if(L>R) swap(L, R);
		if(c) printf("%lld\n", query(1, n, 1));
		else update(1, n, 1);
	}
	return 0;
}

