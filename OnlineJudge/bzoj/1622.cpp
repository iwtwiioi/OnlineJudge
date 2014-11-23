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

const int N=1005;
int f[N][265], n, m, ans;
char a[N][N], md[105][40];

int main() {
	read(n); read(m);
	for1(i, 1, n) { scanf("%s", a[i]+1); for1(j, 1, strlen(a[i]+1)-1) if(a[i][j]>='A'&&a[i][j]<='Z') a[i][j]=a[i][j]-'A'+'a'; }
	for1(i, 1, m) { scanf("%s", md[i]); for1(j, 0, strlen(md[i])-1) if(md[i][j]>='A'&&md[i][j]<='Z') md[i][j]=md[i][j]-'A'+'a'; }
	for1(i, 1, n) {
		CC(f, 0);
		for3(j, strlen(a[i]+1)-1, 0) {
			memcpy(f[j], f[j+1], sizeof(f[j]));
			f[j][(int)a[i][j+1]]=j+1; 
		}
		ans=m;
		for1(j, 1, m) {
			int t=0; 
			for2(k, 0, strlen(md[j])) {
				t=f[t][(int)md[j][k]]; 
				if(!t) { --ans; break; }
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

