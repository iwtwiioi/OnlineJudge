#include <iostream>
using namespace std;
char ans[100000][1000];
int main()
{
    int i = 0;
    while(cin>>ans[i++]){;}
    cout<<ans[i - 1];
	for(int j = i - 2; j >= 0; j--)
        cout<<" "<<ans[j];
    cout<<endl;
    return 0;
}
