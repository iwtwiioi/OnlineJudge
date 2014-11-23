#include <iostream>
#include <string>
using namespace std;
int main()
{
    string ans[10000];
    int i = 0;
    while(cin>>ans[i++]){;}
    for(int j = i - 1; j >= 0; j--)
    {
        cout<<ans[j]<<" ";
    }
    cout<<endl;
    return 0;
}