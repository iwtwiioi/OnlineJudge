#include <cstdio>
#include <algorithm>
using namespace std;
#define lowbit(x) (x&-x)
#define max(a,b) ((a)>(b)?(a):(b))

const int N=50005, M=200005;
int bit[N], a[N], n, m, ihead[1000005], inext[N];
struct Q {
	int l, r, id, ans;
}q[M];
bool cmp1(const Q &a, const Q &b) { return a.l==b.l?a.r<b.r:a.l<b.l; }
bool cmp2(const Q &a, const Q &b) { return a.id<b.id; }

inline int read() {
	int ret=0; char c;
	for(c=getchar(); c<'0' || c>'9'; c=getchar());
	for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0';
	return ret;
}
inline void add(int x, const int &y) { while(x<=n) bit[x]+=y, x+=lowbit(x); }
inline int sum(int x) { int ret=0; while(x>0) ret+=bit[x], x-=lowbit(x); return ret; }

int main() {
	n=read();
	int i, maxi=0, l=1;
	for(i=1; i<=n; ++i) a[i]=read(), maxi=max(maxi, a[i]);
	for(i=n; i>=0; --i) inext[i]=ihead[a[i]], ihead[a[i]]=i;
	for(i=0; i<=maxi; ++i) if(ihead[i]) add(ihead[i], 1);
	m=read();
	for(i=1; i<=m; ++i) q[i].l=read(), q[i].r=read(), q[i].id=i;
	sort(q+1, q+1+m, cmp1);
	for(i=1; i<=m; ++i) {
		while(l<q[i].l) {
			if(inext[l]) add(inext[l], 1);
			++l;
		}
		q[i].ans=sum(q[i].r)-sum(q[i].l-1);
	}
	sort(q+1, q+1+m, cmp2);
	for(i=1; i<=m; ++i) printf("%d\n", q[i].ans);
	return 0;
}
