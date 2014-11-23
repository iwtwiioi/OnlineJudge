#include <iostream>
#include <algorithm>
using namespace std;
int n,i=0,s=0,h=-1000;
struct a{int f,l;bool operator<(const a &t)const{return l>t.l;}}b[100];
int main()
{
    cin>>n;
    for(;i<n;i++)cin>>b[i].f>>b[i].l;
    sort(b,b+n);
    for(i=0;i<n;i++) if(b[i].f>=h){h=b[i].l;s++;}
    cout<<s;
    return 0;
}