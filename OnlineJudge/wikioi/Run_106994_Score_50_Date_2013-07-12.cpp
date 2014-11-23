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
    if(m < 10)
    {
 	  	while(n >= m)
        {
            tp+=char(n%m + '0');
        	n /= m;
        }
        tp+=char(n + '0');
    }
    else
    {
        while(n >= m)
        {
            if(n%m > 9)
            tp+=c[n%m- 10];
        	n /= m;
        }
        tp+=char(n + '0');
    }
    for(int i = tp.size() - 1; i >= 0; i--)
        ans+=tp[i];
    cout<<ans<<endl;
    return 0;
}