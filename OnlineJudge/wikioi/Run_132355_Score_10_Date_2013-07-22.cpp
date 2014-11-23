#include <iostream>
#include <algorithm>
using namespace std;
int a[5010],b[5010]={0};
int main()
{
    int n,i,j,k;
    cin>>n;
    for(i=0,b[0]=1;i<n;i++) cin>>a[i];
    for(i=1;i<n;i++)
        for(j=i-1,k=j;j>=0;j--)
        	if(a[j]>a[k]&&b[j]>b[k])
    		{
        		b[i]=b[j]+1;
        		k=j;
    		}
    sort(&b[0],&b[n]);
    cout<<b[n-1]<<endl;
    return 0;
}