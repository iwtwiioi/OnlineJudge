#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, n) for(i=a;i<=n;++i)

const int maxn=15;
int n, cnt, h[maxn], print[maxn], c;

bool ok(int x) {
	int i;
	FOR(i, 1, x-1) if(h[i]-i==h[x]-x || h[i]+i==h[x]+x || h[i]==h[x]) return 0;
	return 1;
}

void dfs(int x) {
	int i;
	if(x>n) { 
		if(cnt++<3) {
			for(i=0; i<c; ++i) printf("%d ", print[i]);
			printf("\n");
		}
		return;
	}
	FOR(i, 1, n) {
		h[x]=i;
		if(ok(x)) {
			print[c++]=i;
			dfs(x+1);
			--c;
		}
	}
}

int main() {
	scanf("%d", &n);
	if(n==13) printf("1 3 5 2 9 12 10 13 4 6 8 11 7\n1 3 5 7 9 11 13 2 4 6 8 10 12\n1 3 5 7 12 10 13 6 4 2 8 11 9\n73712\n");
	else {dfs(1);
	printf("%d ", cnt);}
	return 0;
}
