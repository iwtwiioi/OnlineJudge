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
#define printarr2(a, b, c) for1(i, 1, b) { for1(j, 1, c) cout << a[i][j]; cout << endl; }
#define printarr1(a, b) for1(i, 1, b) cout << a[i] << ' '; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=1005;
int n, L, can[N][N], len[N];
string s[N], d[N];
char a[N], tp[N];
bool check(int x, int l) {
	int sz=len[x];
	if(l+sz>L) return 0;
	rep(i, sz) if(a[l+i]!='?' && a[l+i]!=s[x][i]) return 0;
	return 1;
}
int main() {
	read(L); read(n);
	scanf("%s", a);
	for1(i, 1, n) scanf("%s", tp), s[i]=tp, len[i]=strlen(tp);
	for1(i, 1, n) rep(j, L) can[i][j]=check(i, j);
	for3(k, L-1, 0)
		for1(i, 1, n) {
			int j=k+len[i];
			if(can[i][k] && (j==L || d[j]!="") && (d[k]=="" || d[k]>s[i]+d[j])) 
					d[k]=s[i]+d[j];
		}
	printf("%s", d[0].c_str());
	return 0;
}