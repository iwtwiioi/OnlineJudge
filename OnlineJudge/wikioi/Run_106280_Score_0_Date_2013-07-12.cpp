
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string temp,ans = "";
    getline(cin,temp);
    int l,f = temp.find(' '),i;
    for(i = temp.size() - 1; i >= f; i--)
    {
        if(temp[i] != ' ')
        {
        	l = i;
            while(i > f && temp[--i] != ' '){;}
            for(int j = i; j <= l; j++)
                ans += temp[j];
            i++;
        }
        else ans += temp[i];
    }
    for(int j = 0; j <= i; j++)
        ans += temp[j];
    cout<<ans<<endl;
    return 0;
}