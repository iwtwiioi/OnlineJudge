#include <iostream>
using namespace std;

int l[20], i, r[20], n, w[20]={0}, wi = 0, h=0;
void dfs(int n, int d)
{
      w[d]++;
      if(l[n]) dfs(l[n], d+1);
      if(r[n]) dfs(r[n], d+1);
      if(d>h) h = d;
}

int main()
{
      cin >> n;
      for(i = 1; i <= n; i++) cin >> l[i] >> r[i];
      dfs(1, 1);
      for(i = 1; i <= h; i++)
            if(w[i]>wi) wi=w[i];
      cout<<wi<<' '<<h;
      return 0;
}

