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

const int N=22;
typedef int mtx[N][N];
mtx a, t, f, b;
int n, m, MD, p[N];
char s[N];
void mul(mtx a, mtx b, mtx c, int la, int lb, int lc) {
	rep(i, la) rep(j, lc) {
		t[i][j]=0;
		rep(k, lb) t[i][j]=(t[i][j]+(a[i][k]*b[k][j])%MD)%MD;
	}
	rep(i, la) rep(j, lc) c[i][j]=t[i][j];
}
int main() {
	read(n); read(m); read(MD);
	scanf("%s", s+1);
	int j=0;
	for(int i=2; i<=m; ++i) {
		while(j && s[i]!=s[j+1]) j=p[j];
		if(s[i]==s[j+1]) ++j;
		p[i]=j;
	}
	rep(i, m) for1(k, 0, 9) {
		j=i;
		while(j && s[j+1]-'0'!=k) j=p[j];
		if(s[j+1]-'0'==k) ++j;
		if(j<m) a[i][j]=(a[i][j]+1)%MD;
	}
	rep(i, m) b[i][i]=1;
	while(n) {
		if(n&1) mul(b, a, b, m, m, m);
		mul(a, a, a, m, m, m);
		n>>=1;
	}
	int ans=0;
	f[0][0]=1;
	mul(f, b, f, 1, m, m);
	rep(i, m) ans=(ans+f[0][i])%MD;
	print(ans);
	return 0;
}