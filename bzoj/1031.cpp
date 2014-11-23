#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define mkpii make_pair<int, int>
#define pdi pair<double, int>
#define mkpdi make_pair<double, int>
#define pli pair<ll, int>
#define mkpli make_pair<ll, int>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define for1(i,a,n) for(int i=(a);i<=(n);++i)
#define for2(i,a,n) for(int i=(a);i<(n);++i)
#define for3(i,a,n) for(int i=(a);i>=(n);--i)
#define for4(i,a,n) for(int i=(a);i>(n);--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define read(a) a=getint()
#define print(a) printf("%d", a)
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define error(x) (!(x)?puts("error"):0)
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=200005;
char s[N];
int t1[N], t2[N], sa[N], c[N];

void st(int *x, int *y, int n, int m) {
	int i;
	for(i=0; i<m; ++i) c[i]=0;
	for(i=0; i<n; ++i) c[ x[y[i]] ]++;
	for(i=1; i<m; ++i) c[i]+=c[i-1];
	for(i=n-1; i>=0; --i) sa[ --c[x[y[i]]] ]=y[i];
}
void hz(char *a, int n, int m) {
	int i, j, p, *x=t1, *y=t2, *t;
	for(i=0; i<n; ++i) x[i]=s[i], y[i]=i;
	st(x, y, n, m);
	for(j=1, p=1; p<n; j<<=1, m=p) {
		for(p=0, i=n-j; i<n; ++i) y[p++]=i;
		for(i=0; i<n; ++i) if(sa[i]>=j) y[p++]=sa[i]-j;
		st(x, y, n, m);
		for(t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; ++i)
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j]?p-1:p++;
	}
}

int main() {
	scanf("%s", s+1);
	int n=strlen(s+1);
	for1(i, 1, n) s[i+n]=s[i];
	s[0]=0;
	hz(s, n*2+1, 256);
	int tot=1, i=1;
	while(tot<=n) {
		//dbg(sa[i]);
		if(sa[i]<=n) {
			printf("%c", s[sa[i]+n-1]);
			++tot;
		}
		++i;
	}
	return 0;
}