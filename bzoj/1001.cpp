#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define for1(i,a,n) for(i=a;i<=n;++i)
#define for2(i,a,n) for(i=a;i<n;++i)
#define for3(i,a,n) for(i=a;i>=n;--i)
#define for4(i,a,n) for(i=a;i>n;--i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define read(a) scanf("%d", &a)
#define print(a) printf("%d", a)

const int N=(999*999*2+2+10), M=N*3, oo=1000000000;
int ihead[N], inext[M], to[M], w[M], cnt;
int vis[N], q[M*2], front, tail, d[M], m;

inline int num(const int &i, const int &j) {
	return ((m-1)*(i-1)<<1)+(j<<1)-1;
}

inline int getnum() {
	int ret=0; char c;
	for(c=getchar(); c<'0' || c>'9'; c=getchar());
	for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0';
	return ret;
}

inline void add(int u, int v, int c) {
	inext[++cnt]=ihead[u]; ihead[u]=cnt; to[cnt]=v; w[cnt]=c;
	inext[++cnt]=ihead[v]; ihead[v]=cnt; to[cnt]=u; w[cnt]=c;
}

inline int spfa(int s, int t, int n) {
	CC(vis, 0);
	int u, i;
	for1(i, 0, n) d[i]=oo;
	vis[s]=1; front=tail=d[s]=0;
	q[tail++]=s;
	while(front<tail) {
		u=q[front++]; if(front==(M<<1)-10) front=0;
		for(i=ihead[u]; i; i=inext[i]) if(d[to[i]]>d[u]+w[i]) {
			d[to[i]]=d[u]+w[i];
			if(!vis[to[i]]) {
				vis[to[i]]=1, q[tail++]=to[i];
				if(tail==(M<<1)-10) tail=0;
			}
		}
		vis[u]=0;
	}
	return d[t];
}

int main() {
	int n;
	n=getnum(); m=getnum();
	int i, j, c;
	int s=(n-1)*(m-1)*2+1, t=s+1;
	for1(i, 1, n) for2(j, 1, m) {
		c=getnum(); 
		if(i==1) add(num(i, j)+1, s, c);
		else if(i==n) add(num(i-1, j), t, c); 
		else add(num(i, j)+1, num(i-1, j), c);
	}
	for2(i, 1, n) for1(j, 1, m) {
		c=getnum();
		if(j==1) add(num(i, j), t, c);
		else if(j==m) add(num(i, j-1)+1, s, c);
		else add(num(i, j), num(i, j)-1, c);
	}
	for2(i, 1, n) for2(j, 1, m) {
		c=getnum();
		add(num(i, j), num(i, j)+1, c);
	}
	print(spfa(s, t, t+1));
	printf("\n");
	return 0;
}

