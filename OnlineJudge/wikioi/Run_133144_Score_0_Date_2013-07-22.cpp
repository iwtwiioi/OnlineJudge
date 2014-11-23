#include <iostream>
#include <algorithm>
using namespace std;
int a[25],n=0,b[25],i,j,c[25]={1},t=1,m,o=0;
int main()
{
    while(cin>>a[n]){b[n]=1;c[n++]=30001;}
    for(i=n-2;i>=0;i--)
        for(j=i;j<n;j++)
        	if(a[i]>a[j]&&b[i]<b[j]+1)
        		b[i]=b[j]+1;
    sort(&b[0],&b[n]);
    cout<<b[n-1]<<endl<<t<<endl;
    return 0;
}