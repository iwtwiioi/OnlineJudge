#include <cstdio>
using namespace std;
#define read(a) a=getnum()
inline int getnum() { int ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }
const int N=10005;
int n, m, u, v, f[N];
inline void sroot(int x) { for(int c=0, fa=f[x]; x; fa=f[x]) { f[x]=c; c=x; x=fa; } }
int main() {
	read(n); read(m); char c;
	for(int i=0; i<m; ++i) {
		for(c=getchar(); c<'A'||c>'Z'; c=getchar());
		read(u); read(v);
		sroot(u);
		if(c=='C') f[u]=v;
		else if(c=='D') f[v]=0;
		else {
			for(; v!=u && v; v=f[v]);
			puts(v==u?"Yes":"No");
		}
	}
	return 0;
}

