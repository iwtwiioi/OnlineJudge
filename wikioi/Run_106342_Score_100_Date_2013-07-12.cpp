#include <iostream>
#include <algorithm>
using namespace std;
int ans[100010];
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>ans[i];
    sort(&ans[0], &ans[n]);
    cout<<ans[0];
    for(int i = 1; i < n; i++)
        cout<<" "<<ans[i];
    return 0;
}