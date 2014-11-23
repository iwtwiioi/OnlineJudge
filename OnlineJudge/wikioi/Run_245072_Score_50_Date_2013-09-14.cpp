#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 1000010;
struct no{ int l,r,d;}node[MAXN];
int n, ans = 0, i;
void dfs(int root)
{
      i = 1;
      if(root == 0) return;
      node[root].d = 1;
      int distance = 0, t;
      stack<int> stack;
      stack.push(root);
      while(!stack.empty())
      {
            t = stack.top();
            stack.pop();
            if(node[t].l != 0)
            {
                  stack.push(node[t].l);
                  node[node[t].l].d = node[t].d+1;
                  distance = (distance < node[t].d+1)?node[t].d+1:distance;
            }
            if(node[t].r != 0)
            {
                  stack.push(node[t].r);
                  node[node[t].r].d = node[t].d+1;
                  distance = (distance < node[t].d+1)?node[t].d+1:distance;
            }
      }
      ans+=distance;
}

int main()
{
      cin >> n;
      for(i = 1; i <= n; i++) cin >> node[i].l >> node[i].r;
      dfs(node[1].l);
      dfs(node[1].r);
      cout<<ans;

      return 0;
}

