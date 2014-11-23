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
int n, L, can[N][N+N], len[N], flag;
string s[N];
char a[N], tp[N];
bool f[N][N];
bool check(int l, int x) {
	int sz=len[x];
	if(l+sz>L) return 0;
	rep(i, sz) if(a[l+i]!='?' && a[l+i]!=s[x][i]) return 0; 
	return 1;
}
int main() {
	read(L); read(n);
	scanf("%s", a);
	for1(i, 1, n) scanf("%s", tp), s[i]=tp;
	sort(s+1, s+n+1);
	for1(i, 1, n) len[i]=s[i].size();
	for1(i, 1, n) rep(j, L) if(check(j, i)) can[i][j]=1;
	for3(k, L-1, 0) {
		for1(i, 1, n) if(can[i][k] && k+len[i]<=L) {
			if(k+len[i]==L) { f[i][k]=1; continue; }
			for1(j, 1, n) if(can[j][k+len[i]] && f[j][k+len[i]]) {
				f[i][k]=1;
				break;
			}
		}
	}
	int pos=0;
	while(pos<L) {
		for1(i, 1, n) if(f[i][pos]) { printf("%s", s[i].c_str()); pos+=len[i]; break; }
	}
	return 0;
}