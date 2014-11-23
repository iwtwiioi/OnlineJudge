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

const int N=12, MX=10000000;
const ll MD=9999997;
ll p[N], c[N], H[MX];
int n, d, ans, vis[N];
bool ifind(ll sum) {
	int t=sum%MD, k=t;
	while(H[k]!=-1) { if(H[k]==sum) return 1; ++k; if(k==MX) k=0; }
	return 0;
}
void hash(ll sum) {
	int t=sum%MD, k=t;
	while(H[k]!=-1) { ++k; if(k==MX) k=0; }
	H[k]=sum;
}
char s[N];
void dfs(int x, ll sum) {
	if(x>n) {
		if(ifind(sum)) return;
		hash(sum);
		if(sum%d==0) ++ans;
		return;
	}
	for1(i, 1, n) if(!vis[i]) {
		vis[i]=1;
		dfs(x+1, p[x]*c[i]+sum);
		vis[i]=0;
	}
}

int main() {
	int cs=getint();
	p[1]=1;
	for1(i, 2, 10) p[i]=p[i-1]*10;
	while(cs--) {
		CC(H, -1);
		scanf("%s", s+1);
		n=strlen(s+1);
		ans=0;
		for1(i, 1, n) c[i]=s[i]-'0';
		read(d);
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}