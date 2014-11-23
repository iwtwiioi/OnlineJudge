#include <iostream>
#include <algorithm>
using namespace std;
int n,i=0,s=0,h,u,o;
struct a{int f,l;bool operator<(const a &t)const{return l>t.l;}}b[100];
int main()
{
    cin>>n;
    for(;i<n;i++){cin>>u>>o;if(u<o){b[i].f=u;b[i].l=o;}else{b[i].f=o;b[i].l=u;}}
    for(i=0;i<n;i++){cout<<i<<':'<<b[i].f<<' '<<b[i].l<<endl;}
    sort(b,b+n);
    for(i=0;i<n;i++){cout<<i<<':'<<b[i].f<<' '<<b[i].l<<endl;}
    for(i=1,h=b[0].f;i<n;i++)
    {
        if(b[i].l<=h)h=b[i].f;
        else if(b[i].l>h&&b[i].f<=h)s++;
        else if(b[i].f>=h)
		{
            s++;h=b[i].f;
    	}
    }
    cout<<s;
    return 0;
}