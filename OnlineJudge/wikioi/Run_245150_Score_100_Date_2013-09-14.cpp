#include <iostream>
#include <algorithm>
using namespace std;
const int MAXE = 5000;
struct ed
{
      int u, v, key;
      bool operator <(const ed &b) const{return key < b.key;}
}edge[MAXE];
int n, i, j, t, e = 0, p[105], x, y, ans = 0;
inline int find(int x){int t=x; while(p[x] != x) x=p[x]; p[t]=x; return x;}
int main()
{
      cin >> n;
      for(i = 0; i < n; i++) { for(j = 0; j < n; j++){cin>>t; if(j>i){edge[e].u=i; edge[e].v=j; edge[e++].key=t;}} p[i]=i;}
      sort(edge, edge + e);
      for(i = 0; i < e; i++)
      {
            x = find(edge[i].u); y = find(edge[i].v);
            if(x != y)
            {
                  ans += edge[i].key;
                  p[x] = y;
            }
      }
      cout << ans;
      return 0;
}

