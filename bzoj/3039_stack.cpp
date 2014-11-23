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
inline int getnum() { int ret=0; char c; for(c=getchar(); c<'0' || c>'9'; c=getchar()); for(; c>='0' && c<='9'; c=getchar()) ret=ret*10+c-'0'; return ret; }

const int N=1005;
int n, m, sum[N][N], s[N], l[N], ans, top;

void update(int h[]) {
	int len;
	top=0; l[top]=s[top]=0;
	for(int i=1; i<=m; ++i) {
		if(h[i]>=s[top]) s[++top]=h[i], l[top]=1;
		else {
			len=0;
			while(top && s[top]>h[i]) {
				len+=l[top];
				ans=max(ans, s[top]*len);
				top--;
			}
			s[++top]=h[i]; l[top]=len+1;
		}
	}
	len=0;
	while(top) {
		len+=l[top];
		ans=max(ans, s[top]*len);
		top--;
	}
}

int main() {
	int c;
	n=getnum(); m=getnum();
	int i, j;
	for1(i, 1, n) for1(j, 1, m) {
		for(c=getchar(); c!='R' && c!='F'; c=getchar());
		if(c=='F') sum[i][j]=sum[i-1][j]+1;
	}
	for1(i, 1, n) update(sum[i]);
	print(ans*3);
	return 0;
}

