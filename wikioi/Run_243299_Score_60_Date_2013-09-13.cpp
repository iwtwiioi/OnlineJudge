#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100000;
const int MAXE = 100000;
long long ans = 0, i, n, e, x, y, r;
long long edge[MAXE] = {0}, p[MAXN] = {0};
struct c
{
      int u, v;
      int w;
}city[MAXE];
int find(int x){ while(p[x] != x) x = p[x]; return x;}
bool cmp(const int &a, const int &b){return city[a].w < city[b].w;}
int main()
{
      cin>>n>>e;
      for(i = 1; i <= e; i++) cin >> city[i].u >> city[i].v >> city[i].w;
      for(i = 1; i <= e; i++) edge[i] = i;
      for(i = 1; i <= n; i++) p[i] = i;
      sort(edge+1, edge+e+1, cmp);
      for(i = 1; i <= e; i++)
      {
            r = edge[i]; x = find(city[r].u), y = find(city[r].v);
            if(x!=y)
            {
                  ans += city[edge[i]].w;
                  p[x] = y;
            }
      }
      cout << ans <<endl;
      return 0;
}