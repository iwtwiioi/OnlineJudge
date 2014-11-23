#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100010;
const int MAXE = 100010;
long long ans = 0;
int i, n, e, x, y;
int p[MAXN] = {0};
struct c
{
      int u, v;
      int w;
      bool operator <(const c &b) const {return w < b.w;}
}edge[MAXE];
inline int find(int x){while(p[x] != x) x = p[x]; return x;}
int main()
{
      cin>>n>>e;
      for(i = 0; i < e; i++) cin >> edge[i].u >> edge[i].v >> edge[i].w;
      for(i = 0; i < n; i++) p[i] = i;
      sort(edge, edge+e);
      for(i = 0; i < e; i++)
      {
            x = find(edge[i].u), y = find(edge[i].v);
            if(x!=y)
            {
                  ans += edge[i].w;
                  p[x] = y;
            }
      }
      cout << ans <<endl;
      return 0;
}
