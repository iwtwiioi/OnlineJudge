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
#define dbg(x) cout << (#x) << " = " << (x) << endl
#define printarr2(a, b, c) for1(_, 1, b) { for1(__, 1, c) cout << a[_][__]; cout << endl; }
#define printarr1(a, b) for1(_, 1, b) cout << a[_] << '\t'; cout << endl
inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }
inline const int max(const int &a, const int &b) { return a>b?a:b; }
inline const int min(const int &a, const int &b) { return a<b?a:b; }

const int N=27, oo=~0u>>1;
int n, m, e[N][N], in[N], s[N], vis[N], top, tp[N], ans[N], tot;
int toposort() {
	top=tot=0; int num=0, ret=0;
	for1(i, 1, n) if(vis[i] && in[i]==0) s[++top]=i;
	for1(i, 1, n) if(vis[i]) ++num;
	for1(i, 1, n) tp[i]=in[i];
	while(top) {
		if(top>1) ret=-1;
		int u=s[top--]; ans[tot++]=u;
		for1(i, 1, n) if(e[u][i] && --tp[i]==0) s[++top]=i;
	}
	if(tot!=num) return ret=1;
	return ret;
}
int main() {
	while(~scanf("%d%d", &n, &m) && !(n==0 && m==0)) {
		CC(e, 0); CC(in, 0); CC(vis, 0);
		int u, v; char s[10];
		int flag=0;
		for1(i, 1, m) {
			scanf("%s", s);
			if(flag==1) continue;
			u=s[0]-'A'+1; v=s[2]-'A'+1; 
			e[u][v]=vis[u]=vis[v]=1; ++in[v];
			flag=toposort(); 
			if(flag==0) {
				if(tot!=n) continue;
				printf("Sorted sequence determined after %d relations: ", i);
				rep(j, tot) printf("%c", 'A'+ans[j]-1);
				puts(".");
				flag=1;
			}
			else if(flag==1) printf("Inconsistency found after %d relations.\n", i);
		}
		if(flag==-1) puts("Sorted sequence cannot be determined.");
	}
	return 0;
}