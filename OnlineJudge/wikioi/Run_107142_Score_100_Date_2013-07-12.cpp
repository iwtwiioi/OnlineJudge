#include <iostream>
#include <string>
using namespace std;
inline const int mi(const int un, const int m)
{
    int r = 1;
 	for(int i = 0; i < m; i++) r *= un;
    return r;
}
const string ch = "ABCDEF";
int main()
{
    int ans = 0, m;
    string n;
    cin>>n>>m;
    int i = 0,s = n.size(), u;
    while(i < s)
    {
        u = s - i - 1;
        if(n[i] > '9')
            ans += (mi(m,u) * (10 + (ch.find(n[i++]))));
        else
        	ans += (mi(m,u) * (n[i++]-'0'));
    }
    cout<<ans<<endl;
    return 0;
}
