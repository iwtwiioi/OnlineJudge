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
#define printarr2(a, b, c) for1(_, 1, b) { rep(__, c) cout << a[_][__] << '\t'; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }
#define rdm(x,i) for(int i=ihead[x]; i; i=e[i].next)

const int N=100005, oo=~0u>>1, MD=1000000007;
int ihead[N], cnt, n, f[N][3], l, r[N], st[N];
ll d[N][3], suml, sumr[N];
struct ED { int to, next; }e[N<<1];
ll mul(ll a, ll b) { return ((a%MD)*(b%MD))%MD;}
ll Plus(ll a, ll b) { return ((a%MD)+(b%MD))%MD;}
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
	e[++cnt].next=ihead[v]; ihead[v]=cnt; e[cnt].to=u;
}
void dfs(int x, int fa) {
	int t1=1, t2=0, s1=1, s2=1, y;
	rdm(x, i) if((y=e[i].to)!=fa) {
		ll tp=0;
		dfs(y, x);
		int mn=min(min(f[y][0], f[y][1]), f[y][2]);

		if(f[y][0]==mn) tp+=d[y][0];
		if(f[y][1]==mn) tp+=d[y][1];
		if(f[y][2]==mn) tp+=d[y][2];
		s1=mul(s1, tp); tp=0;
		s2=mul(s2, d[y][0]);

		t1+=mn;
		t2+=f[y][0];
	}
	f[x][1]=t1;
	f[x][2]=t2;
	
	d[x][1]=s1;
	d[x][2]=s2;

	int sz=0;
	rdm(x, i) if(e[i].to!=fa) st[++sz]=e[i].to;
	r[sz+1]=0; sumr[sz+1]=1; suml=1; l=0;
	for3(i, sz, 1) {
		y=st[i];
		int mn=min(f[y][0], f[y][1]); ll tp=0;
		if(f[y][0]==mn) tp+=d[y][0];
		if(f[y][1]==mn) tp+=d[y][1];
		r[i]=r[i+1]+mn;
		sumr[i]=mul(sumr[i+1], tp);
	}
	f[x][0]=N;
	for1(i, 1, sz) {
		if(l+f[st[i]][1]+r[i+1]<f[x][0]) {
			f[x][0]=l+f[st[i]][1]+r[i+1];
			d[x][0]=mul(d[st[i]][1], mul(suml, sumr[i+1]));
		}
		else if(l+f[st[i]][1]+r[i+1]==f[x][0]) {
			d[x][0]=Plus(d[x][0], mul(d[st[i]][1], mul(suml, sumr[i+1])));
		}
		if(f[st[i]][0]==N) break;
		l+=f[st[i]][0];
		suml=mul(suml, d[st[i]][0]);
	}
}
int main() {
	read(n);
	for1(i, 1, n-1) add(getint(), getint());
	int root=1;
	dfs(root, -1);
	int ans1=min(f[root][1], f[root][0]), ans2=0;
	if(ans1==f[root][0]) ans2=Plus(ans2, d[root][0]);
	if(ans1==f[root][1]) ans2=Plus(ans2, d[root][1]);
	printf("%d\n%d\n", ans1, ans2);
	return 0;
}