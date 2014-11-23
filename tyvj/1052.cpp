#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define FOR(i,a,n) for(i=a;i<=n;++i)
#define CC(i) memset(i,0,sizeof(i))
#define max(a,b) ((a)>(b)?(a):(b))
const int maxn=6005;
int h[maxn], f[maxn][2], root, n;
vector<int> ch[maxn];

void dp(int x) {
	if(f[x][0] || f[x][1]) return;
	if(ch[x].size()==0) {
		f[x][1]=h[x]; return;
	}
	int i;
	FOR(i, 0, ch[x].size()-1) dp(ch[x][i]);
	FOR(i, 0, ch[x].size()-1) 
		f[x][1]+=f[ch[x][i]][0], 
		f[x][0]+=max(f[ch[x][i]][0], f[ch[x][i]][1]);
	f[x][1]+=h[x];
}

int main() {
	scanf("%d", &n);
	int i, a, b, sum=0;
	FOR(i, 1, n) scanf("%d", &h[i]);
	scanf("%d%d", &a, &b);
	while(!(a==0&&b==0)) {
		ch[b].push_back(a);
		sum+=a;
		scanf("%d%d", &a, &b);
	}
	root=((n*(n+1))>>1)-sum; //这里很简单的。。自己想
	dp(root);
	printf("%d\n", max(f[root][0], f[root][1]));
	return 0;
}

