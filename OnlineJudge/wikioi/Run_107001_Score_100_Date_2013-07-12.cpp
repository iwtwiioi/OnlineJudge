#include <iostream>
#include <string>
using namespace std;
const string c = "ABCDEF";
int main()
{
    int n,m,temp;
    cin>>n>>m;
    string ans = "";
    string tp = "";
 	while(n >= m)
    {
        if(n%m > 9)
            tp+=c[n%m- 10];
        else
        	tp+=char(n%m + '0');
        n /= m;
    }
    if(n%m > 9)
        tp+=c[n- 10];
    else
        tp+=char(n + '0');
    for(int i = tp.size() - 1; i >= 0; i--)
        ans+=tp[i];
    cout<<ans<<endl;
    return 0;
}
