#include <iostream>
using namespace std;
int ans = 0;
void dfs(int c)
{
    ans++;
    for(int i = 1; i <= c/2; i++)
        dfs(i);
}
int main()
{
    int a;
    cin>>a;
    dfs(a);
    cout<<ans<<endl;    
    return 0;
}