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

const int N=10005, M=50005;
int ihead[N], cnt, m, n, LL[N], FF[N], s[N], vis[N], top, tot, ans, p[N];
struct ED { int to, next; }e[M+M];
void add(int u, int v) {
	e[++cnt].next=ihead[u]; ihead[u]=cnt; e[cnt].to=v;
}
void tarjan(int x) {
	vis[x]=1;
	s[++top]=x;
	LL[x]=FF[x]=++tot;
	for(int i=ihead[x]; i; i=e[i].next) {
		int y=e[i].to;
		if(!FF[y]) {
			tarjan(y);
			LL[x]=min(LL[x], LL[y]);
		}
		else if(vis[y] && FF[y]<LL[x])
			LL[x]=FF[y];
	}
	if(LL[x]==FF[x]) {
		int t, sum=0; ++ans;
		do {
			t=s[top--];
			vis[t]=0;
			++sum;
			p[t]=ans;
		} while(x!=t);
		if(sum==1) { p[x]=0; --ans; }
	}
}

int main() {
	read(n); read(m);
	for1(i, 1, m) {
		int u=getint(), v=getint();
		add(u, v);
	}
	for1(i, 1, n) if(!FF[i]) tarjan(i);
	print(ans);
	return 0;
}

