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

const int N=50005;
struct Line { double a, b; int id; }l[N];
const bool cmp(const Line &a, const Line &b) { return (abs(a.a-b.a)<=1e-10) ? a.b<b.b : a.a<b.a; }
int n, vis[N], top, st[N];

inline double crossx(const int &x, const int &y) { return (double)(l[x].b-l[y].b)/(l[y].a-l[x].a); }
inline void insert(const int &x) {
	while(top) {
		if(abs(l[st[top]].a-l[x].a)<=1e-10) --top;
		else if(top>1 && crossx(x, st[top])<=crossx(st[top], st[top-1])) --top;
		else break;
	}
	st[++top]=x;
}
int main() {
	read(n);
	for1(i, 1, n) { read(l[i].a); read(l[i].b); l[i].id=i; }
	sort(l+1, l+1+n, cmp);
	for1(i, 1, n) insert(i);
	for1(i, 1, top) vis[l[st[i]].id]=1;
	for1(i, 1, n) if(vis[i]) printf("%d ", i);
	return 0;
}

