#include <iostream>
#include <string>
using namespace std;
int main()
{
    string temp,ans = "";
    getline(cin,temp);
    int l;
    for(int i = temp.size() - 1; i >= 0; i--)
    {
        if(temp[i] != ' ')
        {
        	l = i;
            while(temp[--i] != ' '){;}
            for(int j = i; j <= l; j++)
                ans += temp[j];
        }
        else ans += temp[i];
    }
    cout<<ans<<endl;
    return 0;
}