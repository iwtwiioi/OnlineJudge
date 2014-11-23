#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int MAXE = 5000;
int ans = 0, n, t[MAXN][MAXN], i, j, e = 0;
int edge[MAXE] = {0}, p[MAXN] = {0};
struct c
{
      int u, v;
      int w;
}city[MAXE];

int find(int x) { return (p[x]==x)?x:find(p[x]); }
bool cmp(const int &a, const int &b){return city[a].w < city[b].w;}

void answer()
{
      int x, y, r;
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
}

int main()
{
      cin>>n;
      for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) cin >> t[i][j];
      for(i = 1; i <= n; i++) for(j = i + 1; j <= n; j++) {city[++e].u = i; city[e].v = j; city[e].w = t[i][j];}
      answer();
      cout << ans <<endl;
      return 0;
}

