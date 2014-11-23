#include <cstdio>
using namespace std;
const int MAXN = 100;
bool vis[MAXN];
int c[MAXN];
int n;
void dfs(int x)
{
if(x > n) {for(int i = 1; i <= n; i++)printf("%d", c[i]);printf("\n"); return;}
for(int i = 1; i <= n; i++)
{
if(vis[i]) continue;
c[x] = i;
vis[i] = 1;
dfs(x+1);
vis[i] = 0;
}
}
int main()
{
scanf("%d", &n);
dfs(1);
return 0;
}
			