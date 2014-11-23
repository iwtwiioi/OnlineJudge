#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)

const int maxn=15;
int n, cnt, h[maxn], print[maxn], c, ful;

int gett(int x) {
	int a=1;
	while(x) x>>=1, a++;
	return a;
}

void dfs(int row, int l, int r) {
	if(row==ful) { 
		if(cnt++<3) {
			for(int i=c-1; i>-1; --i) printf("%d ", print[i]);
			printf("\n");
		}
		return;
	}
	int pos=ful&(~(row|l|r)), p;
	while(pos) {
		p=pos&(~pos+1);
		print[c++]=gett(p);
		dfs(row|p, (l|p)>>1, (r|p)<<1);
		--c; pos-=p;
	}
}

int main() {
	scanf("%d", &n);
	ful=(1<<n)-1;
	dfs(0, 0, 0);
	printf("%d ", cnt);
	return 0;
}
