#include <iostream>
using namespace std;
const int MAXN = 100;
bool vis[MAXN];
int c[MAXN];
int n;
void dfs(int x)
{
if(x > n) {for(int i = 1; i <= n; i++)cout<<c[i]<<' ';cout << endl; return;}
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
cin >> n;
dfs(1);
return 0;
}