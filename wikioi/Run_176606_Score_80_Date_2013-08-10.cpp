#include <iostream>
using namespace std;
int v,n,m,w[31];
void dfs(int c, int w1)
{
    if(w1>v) return;
    if(v-w1<m) m=v-w1;
    if(m==0) return;
    for(w1+=w[c];c<n;c++)
        dfs(c+1,w1);
}
int main()
{
	cin>>v>>n;m=v;
	for(int i = 0; i < n; i++) cin>>w[i];
    dfs(0,0);
    cout<<m<<endl;
    return 0;
}
