#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int maxn=20006;
int n, m;
int f[maxn];
vector<int> mis[maxn];

int main() {
	scanf("%d%d", &n, &m);
	int i, j;
	int a, b;
	FOR(i, 1, m) {
		scanf("%d%d", &a, &b);
		mis[a].push_back(b);
	}
	for(i=n; i>0; --i) {
		if(!mis[i].empty()) {
			FOR(j, 0, mis[i].size()-1) f[i]=max(f[i], f[i+mis[i][j]]);
		}
		else f[i]=f[i+1]+1;
	}
	printf("%d\n", f[1]);
	return 0;
}

