#include <iostream>
using namespace std;
const int MAXN = 100010;
int l[MAXN],r[MAXN],d[MAXN]={0};
int n, ans = 0, i;
void dfs(int p)
{
      if(l[p]) dfs(l[p]);
      if(r[p]) dfs(r[p]);
      d[p] = max(d[l[p]], d[r[p]]) + 1;
      ans = max(ans, d[l[p]] + d[r[p]]);
}

int main()
{
      cin >> n;
      for(i = 1; i <= n; i++) cin >> l[i] >> r[i];
      d[1]=0;
      dfs(1);
      cout<<ans;
      return 0;
}

