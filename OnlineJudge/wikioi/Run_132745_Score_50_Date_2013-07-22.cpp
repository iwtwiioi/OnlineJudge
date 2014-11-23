#include <iostream>
#include <algorithm>
using namespace std;
int a[25],n=0,b[25],i,j,c=1;
int main()
{
    while(cin>>a[n]){b[n++]=1;}
    for(i=n-2;i>=0;i--)
        for(j=i;j<n;j++)
        	if(a[i]>a[j]&&b[i]<b[j]+1)
        		b[i]=b[j]+1;
    sort(&b[0],&b[n]);
    for(i=n-1;i>=0;i=j-1)
    {
        for(j=i;j>=0&&b[i]==b[j];j--){}
        if(i-j>c)c=i-j;
    }
    cout<<b[n-1]<<endl<<c<<endl;
    return 0;
}