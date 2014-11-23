#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i,a) memset(i,a,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int H=2100;
int f[H+1][H+1];

int main() {
	int n, i, j, w;
	scanf("%d", &n);
	f[0][0]=1;
	while(n--) {
		scanf("%d", &w);
		for(i=H; i>=0; --i) for(j=H; j>=0; --j)
			if((j>=w && f[i][j-w]) || (i>=w && f[i-w][j])) f[i][j]=1;
	}
	for(i=H; i>0; --i) if(f[i][i]) { printf("%d\n", i); break; }
	if(!i) printf("Impossible\n");
	return 0;
}

