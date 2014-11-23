#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int N=105, M=105, oo=1000000000;
char str[N][M], word[M];
int ssize[N], n, f[M][M];

bool check(int a, int b) {
	bool ok=0;
	int i, j;
	for(i=1; i<=n; ++i) {
		if(ssize[i]==b-a+1) {
			for(j=0; j<ssize[i]; ++j) if(word[a+j]!=str[i][j]) break;
			if(j==ssize[i]) { ok=1; break; }
		}
	}
	return ok;
}

void dp(int i, int j) {
	if(f[i][j]!=-1 || i>j) return;
	if(check(i, j)) { f[i][j]=1; return; }
	int k;
	f[i][j]=oo;
	FOR(k, i, j-1) {
		dp(i, k); dp(k+1, j);
		if(f[i][k]==oo || f[k+1][j]==oo) continue;
		f[i][j]=min(f[i][j], f[i][k]+f[k+1][j]);
	}
}

int main() {
	
	scanf("%s", word);
	scanf("%d", &n);
	int i;
	FOR(i, 1, n) {
		scanf("%s", str[i]);
		ssize[i]=strlen(str[i]);
	}
	ssize[0]=strlen(word);
	CC(f, -1);
	dp(0, ssize[0]-1);
	printf("%d", ((f[0][ssize[0]-1]==-1)||(f[0][ssize[0]-1]==oo)?0:f[0][ssize[0]-1]));
	return 0;
}

