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

const int N=70005;
int a[N], b[N+N], t1[N+N], t2[N+N], c[N+N], sa[N+N], rank[N+N];
void houzhui(int n, int m) {
	int i, j, p, *t, *x=t1, *y=t2;
	for(i=0; i<m; ++i) c[i]=0;
	for(i=0; i<n; ++i) c[ x[i]=a[i] ]++;
	for(i=1; i<m; ++i) c[i]+=c[i-1];
	for(i=n-1; i>=0; --i) sa[--c[x[i]]]=i;
	for(j=1, p=1; p<n; j<<=1, m=p) {
		for(i=n-j, p=0; i<n; ++i) y[p++]=i;
		for(i=0; i<n; ++i) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0; i<m; ++i) c[i]=0;
		for(i=0; i<n; ++i) c[ x[y[i]] ]++;
		for(i=1; i<m; ++i) c[i]+=c[i-1];
		for(i=n-1; i>=0; --i) sa[ --c[x[y[i]]] ]=y[i];
		for(t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; ++i)
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j]?p-1:p++;
	}
}
int n;
int main() {
	char ch;
	read(n);
	for2(i, 0, n) { for(ch=getchar(); ch<'A'||ch>'Z'; ch=getchar()); a[i]=a[(n<<1)-i]=ch-'A'+1; }
	int len=n*2+1;
	houzhui(len+1, 28);
	for1(i, 1, len) rank[sa[i]]=i;
	int l=0, r=n+1;
	while(l+r-n-1<n) {
		if(rank[l]<rank[r]) putchar(a[l++]+'A'-1); else putchar(a[r++]+'A'-1);
		if(!((l+r-n-1)%80)) puts("");
	}
	return 0;
}

