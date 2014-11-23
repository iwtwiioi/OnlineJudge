#include <iostream>
#include <algorithm>
using namespace std;

int a[25],n=0,b[25],i,j,s[25],x=1,x1,y=1,w=1929492;
int main()
{
    while(cin>>a[n]) b[n++]=1;
    for(i=n-2;i>=0;i--)
        for(j=i;j<n;j++)
            if(a[i]>a[j]&&b[i]<b[j]+1)
                b[i]=b[j]+1;
    sort(b,b+n);
    s[1]=a[0];
    for(i=1;i<n;i++)
    {
        x1=-1;w=1929492;
        for(x=1;x<=y;x++)
            if(s[x]>a[i]&&s[x]<w)
            {
                w=s[x];
                x1=x;
            }
        (x1==-1)?s[++y]=a[i]:s[x1]=a[i];
    }
    cout<<b[n-1]<<endl<<y<<endl;
    return 0;
}
